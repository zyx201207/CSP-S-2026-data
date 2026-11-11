#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long 
#define db double 
struct node{
	int x;
	char c;
	ll st,en;
};




int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<node> a(n+1);
	ll len=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		
	}
	for(int i=1;i<=n;i++){
		a[i].st=len+1;
		len+=a[i].x;
		a[i].en=len;
	}
	ll l=1,r=len;
	int ti1=1,ti2=n;
	ll ans=0;
	while(l <= len/2 && r >= len/2){
		int x=min(a[ti1].en-l+1 , r-a[ti2].st+1);
		if(a[ti1].c != a[ti2].c) ans+=x;
		l+=x;
		r-=x;
		if(l == a[ti1].en+1) ti1++;
		if(r == a[ti2].st-1) ti2--;
		
	}
	cout<<ans;
	
	
	
	
	return 0;
}

