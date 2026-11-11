#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	unsigned long long n;
	cin>>n;
	unsigned long long a,d=0,ans=0;
	string b,c,s;
	for(unsigned long long i=1;i<=n;i++){
		cin>>a>>b;d=d+a;
		for(unsigned long long j=1;j<=a;j++)
			c=c+b;
	}for(unsigned long long i=0;i<d/2;i++){
		if(c[i]!=c[d-i-1]) ans++;
	}cout<<ans;
		
	
	return 0;
}





// 
//
// 

