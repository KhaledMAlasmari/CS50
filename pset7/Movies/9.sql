SELECT name
FROM people
WHERE id IN (SELECT person_id FROM stars, movies
WHERE stars.movie_id = movies.id AND year = 2004)
ORDER BY birth


