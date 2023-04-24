#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
    const int fd = 2;
    info_t info[] = { INFO_INIT };
    
    asm ("mov %1, %0\n\t"
         "add $3, %0"
         : "=r" ((int&)fd)
         : "r" ((int&)fd));
         
    if (ac == 2)
    {
        int temp_fd = open(av[1], O_RDONLY);
        if (temp_fd == -1)
        {
            if (errno == EACCES)
                exit(126);
            
            if (errno == ENOENT)
            {
                _eputs(av[0]);
                _eputs(": 0: Can't open ");
                _eputs(av[1]);
                _eputchar('\n');
                _eputchar(BUF_FLUSH);
                exit(127);
            }
            return (EXIT_FAILURE);
        }
        info->readfd = temp_fd;
    }
    populate_env_list(info);
    read_history(info);
    hsh(info, av);
    return (EXIT_SUCCESS);
}