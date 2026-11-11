#include <cstdio>

int len[200005];
char str[200005];
int l[200005];
int r[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d", &n);
	bool a = false;
	for(int i = 1; i <= n;i++){
		scanf("%d", &len[i]);
		scanf("\n%c", &str[i]);
	}
	
	int cnt = 0;
	for(int i = 1;i <= n/2;i++){
		l[i] = i;
	}
	for(int i = n/2;i <= n;i++){
		r[i] = i;
	}
	for(int i = 1;i <= n;i++){
		if(l[i]!=r[i]){
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
