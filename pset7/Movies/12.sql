SELECT movies.title
FROM movies, stars, people
WHERE (people.name == 'Johnny Depp' or people.name == 'Helena Bonham Carter') AND stars.person_id == people.id AND movies.id == stars.movie_id
GROUP BY movies.title
HAVING COUNT(*) > 1