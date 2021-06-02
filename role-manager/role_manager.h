#ifndef XML_MANAGER_H
#define XML_MANAGER_H

#include <stdbool.h>
#include <libxml/parser.h>

#define XML_FILE "./file.xml"

#define ADDROLE 0
#define EDITROLE 1
#define DELETEROLE 2

#define CAP 0
#define USER 1
#define GROUP 2
#define USERCOM 3
#define GROUPCOM 4

#define MAX_ROLE_LEN 64
#define MAX_NAME_LEN 32
#define MAX_COMMAND_LEN 256

typedef struct arguments {
  char *rolename;
  bool capability[43]; // 42 capabilities + all capabilities
  /* User */
  int uc;
  int ui;
  /* **** */

  /* Group */
    int gc;
    int gi;
  /* ***** */

  /* Commands */
  int cc[2];
  int ci[2][10]; // First line -> usercommand | Second line -> groupcommand
  /* ******** */
} args_struct;

/* Enlever les args pour editorle */
xmlDocPtr xml_verifier(void);
int role_verifier(xmlDocPtr doc, xmlNodePtr *role_node, char *role);
int capability_verifier(char *cap_text, args_struct *args);
int user_verifier(char *users, args_struct *args);
int group_verifier(char *groups, args_struct *args);
int command_verifier(char *command);
/* ***************************** */

xmlNodePtr researchNode(xmlNodePtr role_node, int elem, char *text);
int addNode(xmlNodePtr *elem, char *parent, char *text);
void deleteNode(xmlNodePtr elem);

void print_help (int command);

#endif