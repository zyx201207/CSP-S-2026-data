#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
char c[N],y;
int n,x,mid,len=0,ans,le[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		len+=x;
		le[i]=x;
		c[i]=y;
	}
	int l=1,r=n,ll=0,rr=0;
	while(l<r){
		if(le[l]<=le[r]){
			if(c[l]!=c[r]) ans+=le[l];
			ll+=le[l];
			rr+=le[l];
			le[r]-=le[l++];
		}
		else if(le[l]>le[r]){
			if(c[l]!=c[r]) ans+=le[r];
			rr+=le[r];
			ll+=le[r];
			le[l]-=le[r--];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

