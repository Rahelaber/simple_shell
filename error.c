int error_check(void) 
{ 
    char *input = NULL; 
    size_t len = 0; 
    ssize_t read; 

    while (1) { 
        puts("$ "); 
        read = getline(&input, &len, stdin); 

        if (read == -1) { 
           perror("getline"); 
           exit(EXIT_FAILURE); } 

// Execute commands based on 'input' here 
// Handle command not found error 

    } 

    free(input); 
    return 0;

