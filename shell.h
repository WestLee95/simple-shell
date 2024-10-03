/* Constants */
#define MAX_ARG_COUNT    1024     /* Maximum number of arguments per command */
#define MAX_HISTORY_ITEMS 100     /* Maximum number of commands in history */

/* Structure for a parsed command */
struct command {
    int argc;                      /* Number of arguments */
    char *name;                    /* Command name */
    char *argv[MAX_ARG_COUNT];     /* Command arguments */
    int fds[2];                    /* File descriptors for input/output */
};

/* Structure for a command pipeline */
struct commands {
    int cmd_count;                 /* Number of commands in the pipeline */
    struct command *cmds[];        /* Array of commands */
};

/* Function declarations */
int clear_history(void);
int add_to_history(char *command);
int handle_history(struct commands *cmd_pipeline, struct command *cmd);
int exec_command(struct commands *cmd_pipeline, struct command *cmd, int pipes[][2]);
void cleanup(void);
int is_history_command(char *input);
int is_blank_input(char *input);
void close_pipes(int pipes[][2], int num_pipes);
