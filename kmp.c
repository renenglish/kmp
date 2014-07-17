#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int kmp(const char *s, const char *sub){
	int ls = strlen(s);
	int lsub = strlen(sub);
	char *next = malloc(lsub);

	/*Build the next array*/
	int i = 0;
	int n = 0;
	int j = 0;
	for(i = 0; sub[i]; ++i){
		j = 1;
		n = 0;
		while(j < i){
			if(sub[n] == sub[j]){
				++n;
			}else{
				if(n!=0){
					--j;
				}
				n = 0;
			}
			++j;
		}
		next[i] = n;
		printf("next[%d]=%d\n", i, n);
	}

	/*Search the substring*/
	j = 0;
	for(i = 0; s[i] && sub[j]; ++i, ++j){
		if(s[i] != sub[j]){
			j = next[j];
			if(s[i]!=sub[j]){
				j = -1;
			}
		}
	}
	if(j == lsub){
		return i-j;
	}
	return -1;
}

int main(int argc, char *argv[]){
	const char *s = "aaaaaaaaaaaaaaaaaaaaaaaaaab";
	const char *sub = "ababac";
	int idx = kmp(s, sub);
	if(idx == -1){
		printf("Not found!\n");
		return 1;
	}
	printf("idx:%d\n", idx);
	printf("%s\n", s);
	while(idx-- > 0){
		printf(" ");
	}
	printf("%s\n", sub);
	return 0;
}
