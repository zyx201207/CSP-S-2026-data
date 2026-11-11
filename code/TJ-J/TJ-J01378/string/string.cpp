#include<bits/stdc++.h>
using namespace std;
int n;
long long l,num;
char c[1000000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long m=0;
		char a=' ';
		cin>>m>>a;
		for(long long j=l+1;j<=l+m;j++){
			c[j]=a;
		}
		l+=m;
	}
	for(int i=1;i<=l/2;i++){
		if(c[i]!=c[l+1-i])num++;
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
