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
	next[0] = 0;
	char c;
	for(i = 1; sub[i]; ++i){
		n = next[i-1];
		c = sub[n];
		if(i-1 <= n){
			next[i] = 0;
		}else if(c == sub[i-1]){
			next[i] = n + 1;
		}else{
			next[i] = 0;
		}
		printf("next[%d]=%d\n", i, next[i]);
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
	const char *s = "abcabdeababadababaeabaabcac";
	const char *sub = "abadef";
	int idx = kmp(s, sub);
	if(idx == -1){
		printf("Can not find %s in %s!\n", sub, s);
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
