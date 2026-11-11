#include<bits/stdc++.h>
#define ll long long
using namespace std;
int z[800009],n;
ll l[800009],len[800009],r[800009];
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char x;
		cin>>len[i]>>x;
		z[i]=x+1-'a';
		l[i]=r[i-1]+1;
		r[i]=l[i]+len[i]-1;
	}
//	for(int i=1;i<=n;i++)cout<<l[i]<<" "<<r[i]<<" "<<z[i]<<"\n";
	ll L=r[n];
	int li=1,ri=n;
	while(li<ri){
		if(z[li]!=z[ri]){
			ans+=min(r[li],L-l[ri]+1)-max(l[li],L-r[ri]+1)+1;
		}
//		cout<<li<<" "<<ri<<" "<<ans<<"\n";
		bool x=0,y=0;
		if(r[li]>=L-l[ri]+1){
			x=1;
		}
		if(r[li]<=L-l[ri]+1){
			y=1;
		}
		if(x)ri--;
		if(y)li++;
		
	}
	cout<<ans;
	return 0;
} 
