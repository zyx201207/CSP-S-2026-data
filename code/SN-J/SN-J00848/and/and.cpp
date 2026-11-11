#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long v[N];
int main(){
	//黎倚睿 SN-J00848 延安市新区第一中学 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long q,x,a,b,c,ans=0;
	cin>>q>>x;
	for(long long i=0;i<q;i++){
		cin>>v[i];
	}
	for(long long j=0;j<x;j++){
	for(long long i=0;i<q;i++){
		c=v[i]&v[i+1];
		ans=max(c,ans);
	}	
	}
	
	cout<<ans;
	return 0;
}
