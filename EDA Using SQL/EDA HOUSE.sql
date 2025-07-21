select*from House

SELECT TOP 5 * FROM House;

select count(*) as Total_ROWS from House

SELECT price, COUNT(*) AS freq
FROM House
GROUP BY price
ORDER BY freq DESC;

SELECT COLUMN_NAME
FROM INFORMATION_SCHEMA.COLUMNS
WHERE TABLE_NAME = 'House';


EXEC sp_rename 'House.view', 'v_count', 'COLUMN';

select*from House


SELECT COLUMN_NAME
FROM INFORMATION_SCHEMA.COLUMNS
WHERE TABLE_NAME = 'House';


SELECT 
    id, date, price, bedrooms, bathrooms, sqft_living, floors, waterfront,
    v_count, condition, grade, yr_built, yr_renovated, zipcode, lat, long,
    sqft_living15, sqft_lot15, sqft_lot, sqft_above, sqft_basement
FROM House
GROUP BY 
    id, date, price, bedrooms, bathrooms, sqft_living, floors, waterfront,
    v_count, condition, grade, yr_built, yr_renovated, zipcode, lat, long,
    sqft_living15, sqft_lot15, sqft_lot, sqft_above, sqft_basement
HAVING COUNT(*) > 1;


select*from House


SELECT 
    SUM(CASE WHEN id IS NULL THEN 1 ELSE 0 END) AS id_nulls,
    SUM(CASE WHEN date IS NULL THEN 1 ELSE 0 END) AS date_nulls,
    SUM(CASE WHEN price IS NULL THEN 1 ELSE 0 END) AS price_nulls,
    SUM(CASE WHEN bedrooms IS NULL THEN 1 ELSE 0 END) AS bedrooms_nulls,
    SUM(CASE WHEN bathrooms IS NULL THEN 1 ELSE 0 END) AS bathrooms_nulls,
    SUM(CASE WHEN sqft_living IS NULL THEN 1 ELSE 0 END) AS sqft_living_nulls,
    SUM(CASE WHEN floors IS NULL THEN 1 ELSE 0 END) AS floors_nulls,
    SUM(CASE WHEN waterfront IS NULL THEN 1 ELSE 0 END) AS waterfront_nulls,
    SUM(CASE WHEN condition IS NULL THEN 1 ELSE 0 END) AS condition_nulls,
    SUM(CASE WHEN grade IS NULL THEN 1 ELSE 0 END) AS grade_nulls,
    SUM(CASE WHEN yr_built IS NULL THEN 1 ELSE 0 END) AS yr_built_nulls,
    SUM(CASE WHEN yr_renovated IS NULL THEN 1 ELSE 0 END) AS yr_renovated_nulls,
    SUM(CASE WHEN zipcode IS NULL THEN 1 ELSE 0 END) AS zipcode_nulls,
    SUM(CASE WHEN lat IS NULL THEN 1 ELSE 0 END) AS lat_nulls,
    SUM(CASE WHEN long IS NULL THEN 1 ELSE 0 END) AS long_nulls,
    SUM(CASE WHEN sqft_living15 IS NULL THEN 1 ELSE 0 END) AS sqft_living15_nulls,
    SUM(CASE WHEN sqft_lot15 IS NULL THEN 1 ELSE 0 END) AS sqft_lot15_nulls,
    SUM(CASE WHEN sqft_lot IS NULL THEN 1 ELSE 0 END) AS sqft_lot_nulls,
    SUM(CASE WHEN sqft_above IS NULL THEN 1 ELSE 0 END) AS sqft_above_nulls,
    SUM(CASE WHEN sqft_basement IS NULL THEN 1 ELSE 0 END) AS sqft_basement_nulls
FROM House;


SELECT 
    COLUMN_NAME, 
    DATA_TYPE, 
    CHARACTER_MAXIMUM_LENGTH
FROM INFORMATION_SCHEMA.COLUMNS
WHERE TABLE_NAME = 'House';


SELECT AVG(price) AS avg_price FROM House;

select*from House


SELECT floors, COUNT(*) AS frequency
FROM House
GROUP BY floors
ORDER BY frequency DESC;


SELECT waterfront, COUNT(*) AS frequency
FROM House
GROUP BY waterfront
ORDER BY frequency DESC;



SELECT bathrooms, COUNT(*) AS frequency
FROM House
GROUP BY bathrooms
ORDER BY frequency DESC;


SELECT bedrooms, COUNT(*) AS frequency
FROM House
GROUP BY bedrooms
ORDER BY frequency DESC;

SELECT grade, COUNT(*) AS frequency
FROM House
GROUP BY grade
ORDER BY frequency DESC;

SELECT v_count, COUNT(*) AS frequency
FROM House
GROUP BY v_count
ORDER BY frequency DESC;


select*from House

select TOP 5 yr_built,AVG(price) as AVERAGE_OF_PRICE_PER_YEAR
from 
House 
group by yr_built
order by AVERAGE_OF_PRICE_PER_YEAR DESC


select yr_built ,count(*) as COUNTT_ from House
group by yr_built
order by yr_built desc


SELECT 
  date,
  CAST(LEFT(date, 8) AS DATE) AS cleaned_date
FROM 
  House;

update House
set date=left(date,8)

select*from House

ALTER TABLE House
ALTER COLUMN date DATE;

select *from House


select yr_renovated , count(*) as FREQ
from 
House
group by yr_renovated 

select yr_renovated , AVG(price) as AVERAGE
from 
House
group by yr_renovated 


