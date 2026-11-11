#include<bits/stdc++.h>
using namespace std;
int n,top=0;
char s[100000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin >> x >> c;
		for(int j=1;j<=x;j++)
			s[++top]=c;
	}
	long long sum=0;
	for(int i=1;i<=top/2;i++){
		if(s[i]!=s[top-i+1])
			sum++;
	}
	printf("%lld\n",sum);
}
