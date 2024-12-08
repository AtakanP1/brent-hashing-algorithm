This project implements a hash table using Brent’s Method, focusing on optimizing collision resolution and enhancing search efficiency. The algorithm minimizes the number of probes required to resolve collisions by intelligently determining the optimal insertion point, balancing probe length and displacement. A key component of this implementation is the calculateLQ function, which computes possible insertion indices based on a given index and increment value.

Features:


-Hash Table Initialization: The hash table is initialized with a user-defined size.

-Insertion with Brent’s Method: Efficiently inserts values by calculating the best possible index to reduce collisions.

-Probe Counting: Determines the number of probes (or "hops") needed to find a specific key in the hash table.

-Average Probes Calculation: Computes the average number of probes required to find all keys, offering a performance metric for the hash table.
