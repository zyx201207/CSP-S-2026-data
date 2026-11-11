#include<bits/stdc++.h>
#define int long long
using namespace std;
int s[200005];
int c[200005];



signed main(){
	//ios::sync_with_stdio(false);
	///cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxx=0x8080808080808080;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	bool flag=true;
	for(int i=1;i<n;i++){
		c[i+1]=s[i+1]-s[i];
		if(i!=1&&c[i+1]!=c[i]) flag=false;
	}
	if(flag){
		if(c[n]==0) cout<<n;
		else cout<<m/c[n];
		return 0;
	}
    int l=1,r=1;
    unsigned long long cnt=0;
    for(int i=2;i<=n;i++){
    	cnt=cnt+(r-l+1)*(s[i]-s[i-1]);
    	r++;
    	while(cnt>m){
    		cnt-=(s[r]-s[l]);
    		l++;
		}
		maxx=max(maxx,r-l+1);
	}
    cout<<maxx;
	return 0;
}
