-- The answer log to the mystery !

-- 1. We have one information, the date and location of the theft. Let's look at the crime_scene_reports first.
SELECT *
FROM crime_scene_reports
WHERE year = 2023 AND month = 7 AND day = 28
AND street =  "Humphrey Street";

-- We got 2 results: The theft and some littering. but we are interested in the Theft itself !
-- We got 3 things out of this query : The Humphrey Street Bakery, the time (10:15 am) and that we have 3 witnesses whom mention the bakery

-- 2. Let's go check those interviews:
SELECT transcript
FROM interviews
WHERE year = 2023 AND month = 7 AND day = 28
AND transcript LIKE '%bakery%'; 

-- The plot thickens !
-- A getaway car, A withdrawal at the ATM of Leggett Street and a call to get plane tickets first time tomorrow morning !

-- 3. Let's check the flight first
-- We want to know where the Thief is going
SELECT airports.abbreviation, airports.full_name, airports.city, flights.id
FROM airports
JOIN flights ON flights.destination_airport_id = airports.id
WHERE flights.year = 2023 AND flights.month = 7 AND flights.day = 29
ORDER BY hour ASC
LIMIT 1;

-- Going to New Work, LaGuardia Airport ! (flisht ID 36)

-- 4. Let's check the ATM logs and who they belong to
SELECT people.name, people.passport_number, people.phone_number, people.license_plate
FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE atm_transactions.year = 2023 AND atm_transactions.month = 7 AND atm_transactions.day = 28
AND atm_location = "Leggett Street";

-- "name",      "passport_number",  "phone_number",     "license_plate
----------------------------------------------------------------------
-- "Bruce",     5773159633,         "(367) 555-5533",   "94KL13X"
-- "Kaelyn",    8304650265,         "(098) 555-1164",   "I449449"
-- "Diana",     3592750733,         "(770) 555-1861",   "322W7JE"
-- "Brooke",    4408372428,         "(122) 555-4581",   "QX4YZN3"
-- "Kenny",     9878712108,         "(826) 555-1652",   "30G67EN"
-- "Iman",      7049073643,         "(829) 555-5269",   "L93JTIZ"
-- "Luca",      8496433585,         "(389) 555-5198",   "4328GD8"
-- "Taylor",    1988161715,         "(286) 555-6063",   "1106N58"
-- "Benista",   9586786673,         "(338) 555-6650",   "8X428L0"

-- 5. Now, the cars
-- We have the car plates, we can found whom car the thief used.
SELECT people.name, bakery_security_logs.license_plate
FROM bakery_security_logs
JOIN people ON people.license_plate = bakery_security_logs.license_plate
WHERE bakery_security_logs.license_plate IN ('94KL13X', 'I449449', '322W7JE', 'QX4YZN3', '30G67EN', 'L93JTIZ', '4328GD8', '1106N58', '8X428L0')
AND year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25
AND bakery_security_logs.activity = "exit";

-- "name",  "license_plate"
------------------------
-- "Bruce", "94KL13X"
-- "Luca",  "4328GD8"
-- "Iman",  "L93JTIZ"
-- "Diana", "322W7JE"

-- 6. Check who the theif called
SELECT caller.name as Caller, receiver.name AS Receiver, caller.license_plate, caller.passport_number
FROM phone_calls
JOIN people caller ON phone_calls.caller = caller.phone_number
JOIN people receiver ON phone_calls.receiver = receiver.phone_number
WHERE year = 2023 AND month = 7 AND day = 28 AND duration <= 60;

-- "Caller",    "Receiver",     "license_plate",    "passport_number"
---------------------------------------------------------------------
-- "Sofia",     "Jack",         "G412CB7",          1695452385
-- "Kelsey",    "Larry",        "0NTHK55",          8294398571
-- "Bruce",     "Robin",        "94KL13X",          5773159633
-- "Kathryn",   "Luca",         "4ZY7I8T",          6121106406
-- "Kelsey",    "Melissa",      "0NTHK55",          8294398571
-- "Taylor",    "James",        "1106N58",          1988161715
-- "Diana",     "Philip",       "322W7JE",          3592750733
-- "Carina",    "Jacqueline",   "Q12B3Z3",          9628244268
-- "Kenny",     "Doris",        "30G67EN",          9878712108
-- "Benista",   "Anna",         "8X428L0",          9586786673

-- 7. Check the passengers list
SELECT *
from people
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE passengers.passport_number IN ('5773159633', '3592750733') AND passengers.flight_id = 36;

-- 686048,  "Bruce",    "(367) 555-5533",   5773159633, "94KL13X",  36, "4A"
