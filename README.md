# NAT

Thank you for taking the time to review my code =)

What I didn't finish: 
  - My output file isn't in the correct order and not all FLOW translations are printed. If I had more time I'd go through my         
    searchNAT() and writeOutput() functions and use print statements to check what values are being stored in my results map 
    and how they are being stored to see why the output is partially incorrect.  

Testing: 
  - I used print statements throughout my code to verify expected behavior 
  - I tested different variations of input to verify improper formats were handled correctly
  - I checked the output by observation
  - I included the input and output files from testing
  
Refinements & Optimizations:
  - Since my output file isn't as expected, this would be my first fix. 
  - I would have changed my searchNat() function to return a string rather than void, and pass the current flow as a 
    parameter. This way when writing to the OUTPUT file, writeOutput() function would call the searchNat() function and it    
    would return either the NAT found or a string saying "No NAT match for" and write the result to the file. This would 
    eliminate the need for my result_ map as a private member variable. 
  - I would overload the insertion operator to clean up writeOutput() function 
  - There may be a better way to implement my searchNat() function to find the possible matches for the given flow. One   
    possibility would be mapping all variations to the nat table when reading in the nat file instead. This would allow one 
    search instead of 3. 
  - I also would have tested larger sets of data. Since I ran out of time I didn't get to check the performance of larger 
    input files.
    
Assumptions: 
  - I assumed the imput files would contain ip addresses of 32-bits in appropriate dot-decimal notation and port numbers of   
    16-bits. Given more time I would have validated this as well. 
  - I assumed that since this was a simplified NAT it was a one-to-one translation rather than one-to-many.
  - I assumed the second <ip>:<port> pair in the NAT input file could not have a * in it for a valid translation (this was not 
    specified in the coding challenge requirements). I validated this condition in my validateNat() function. 
