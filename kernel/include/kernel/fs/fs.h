typedef struct {
    char name[20];
    int size;
    int start;
    int end;
} file;

typedef struct {
    char name[20];
    int size;
    int start;
    int end;
} directory;

typedef struct {
    char name[20];
    directory *root;
} disk;

file read_file(char *path) {

}

void create_file(char *path) {

}

void delete_file(char *path) {

}

directory read_directory(char *path) {

}

void create_directory(char *path) {

}

void delete_directory(char *path) {

}

disk read_disk(char *path) {

}

void create_disk(char *path) {

}

void delete_disk(char *path) {

}

