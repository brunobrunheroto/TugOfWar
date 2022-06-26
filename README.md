# Tug Of War
<p>Tug of war is a project made is C language that demonstrates the dispute between different threads for the position of a flag in an array filled with underscore characters "_".</p>

### Goals
<p>This project was made for academic purposes and aims to demonstrate how threads work and how they behave during runtime.</p>

### How it works
<p>Initially, an array of 88 positions is created and filled with underscore characters "_". The flag, formed by three characters "ABC", is then placed exactly in the middle of the array, at positions 42, 43 and 44. The last position of the array will always be a character "\0" (string terminator).</p>
<p>Once this is done, the initial appearance of the vector should look like this:</p>
<p>__________________________________________ABC__________________________________________\0</p>
<p>The initial flag position, 42, is stored in a variable x, and is used to modify the flag's position at runtime.</p>
<p>The threads that will compete are called "tothestart" and "totheend". "tothestart" subtracts 1 from x and "totheend" adds 1 from x. Both modify the flag's position using the x position, bringing it closer to the start or end respectively and sleep for a period "t", calculated through the function:</p>
<p>t = (long) (drand48() * 202010101/89.0);</p> 
<p>The program then draws quantities q1 and q2 of threads, obeying 7 <= (q1,q2) <= 22 and creates them. q1 will be the number of "tothestart" threads and q2 the number of "totheend" threads.</p>
<p>The threads are created alternately, so that none has an advantage over the other on the competition.</p>
<p>After the threads are created, the main thread will continue to run concurrently with them an execution loop with the following commands:</p>
<p>Clear the screen: system("clear");</p>
<p>Print q1 and q2: printf("tothestart: %d\ttotheend: %d\n", q1, q2);</p>
<p>Print the array:  printf("%s\n", a);</p>
<p>Test the character position (x) of your name. If it reaches the beginning (0), or the end (86-2), it will display a message pointing to the winning thread team (totheend or tothestart) and then end the game.</p>
<p>At each execution, the main thread sleeps for an adjusted period of time so as not to overload the processing.</p>

### How to use
<p>Download the TugOfWar.c file on this repository.</p>
<p>Install codeblocks.</p>
<p>On Settings -> Compiler -> Linker Settings, add -pthread to the "Other Linker options" field.</p>
<p>Click "Compile and Run" or "Compile" and "Run" respectively.</p>

### Credits
<p> The ideia to make this project and it's structure was shared by the teacher of Operating Systems at Facamp, José Martins Junior.</p>
