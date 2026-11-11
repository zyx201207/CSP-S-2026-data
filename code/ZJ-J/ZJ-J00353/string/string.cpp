#include<bits/stdc++.h>
using namespace std;
long long n,i,m,k,j,z;
string s;
char a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>m>>a;
		k+=m;
		for(j=1;j<=m;j++){
			s[j]=a;
		}
	}
	for(i=1;i<=k/2;i++){
		if(s[k-i]!=s[i]){
			z++;
			s[i]=s[k-i];
		}
	}
	cout<<j;
	return 0;
}
