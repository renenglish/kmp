#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int kmp(const char *s, const char *sub){
	int ls = strlen(s);
	int lsub = strlen(sub);
	char *next = malloc(lsub);

	/*Build the next array*/
	int i = 1;
	int n = 0;
	int j = 0;
	next[0] = 0;

	while(sub[i]){
		if(i - 1 <= next[n]){
			next[i] = 0;
			++i;
		}
		if(sub[i-1] != sub[next[n]]){
			n = next[n];
			if(n == 0){
				next[i] = 0;
				n = i;
				++i;
			}
		}else{
			next[i] = next[n] + 1;
			n = i;
			++i;
		}
	}
	for(i = 0; sub[i]; ++i){
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
	const char *sub = "abaabc";
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
