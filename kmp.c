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
	return 0;
}

int main(int argc, char *argv[]){
	const char *s = "abacababcababac";
	const char *sub = "abaabcac";
	int idx = kmp(s, sub);
	printf("idx:%d\n", idx);
	printf("%s\n", s);
	while(idx-- > 0){
		printf(" ");
	}
	printf("%s\n", sub);
	return 0;
}
