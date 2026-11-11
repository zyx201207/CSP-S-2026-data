#include<bits/stdc++.h>
using namespace std;
int n,a,len,ans;
char x,s[1000000001];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	while(n--) {
		cin>>a>>x;
		while(a--)
			s[len++]=x;
	}
	int m=(len>>1);
	for(int i=0;i<m;i++)
		ans+=(s[i]!=s[len-i-1]);
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
