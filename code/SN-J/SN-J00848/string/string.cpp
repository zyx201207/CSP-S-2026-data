#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5; 
int main(){
	//黎倚睿 SN-J00848 延安市新区第一中学 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char c[N];
	long long a,b,ans=0;
	long long q=0;
	char d;
	cin>>a;
	for(long long i=0;i<a;i++){
		cin>>b>>d;
	for(long long j=q;j<b+q;j++){
		c[j]=d;
	}
	q+=b;
	}
	for(long long i=0;i<q;i++){
		if(c[i]!=c[q-i-1]) ans++;
		if(i==q/2) break;
	}
	cout<<ans;
	return 0;
}
