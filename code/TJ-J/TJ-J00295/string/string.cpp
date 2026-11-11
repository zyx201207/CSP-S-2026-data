#include<bits/stdc++.h>
using namespace std;
long long n,cnt,ans,m,p;
long long a;
char c;
long long b[200000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			b[p+j]=c-'a'+1;
		}
		p+=a;
	}
	for(int i=1;i<=p/2;i++){
		if(b[i]!=b[p-i+1])m++;
	}
	cout<<m;
	return 0;
} 
