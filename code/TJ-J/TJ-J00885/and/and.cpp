//666这又是啥阴，气死吾了  WA=Wonderful Answer
#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<int,bool> mp;
ll n,m,a[200005],mx=-1e9,t[10];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool ppp=1,bbb=1;
	mp[2]=mp[4]=mp[8]=mp[16]=mp[32]=mp[64]=mp[128]=mp[256]=mp[512]=mp[1024]=mp[2048]=mp[4096]=mp[8192]=mp[16384]=mp[32768]=mp[65536]=mp[131072]=mp[262144]=mp[524288]=mp[1048576]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!mp[a[i]+1]){
			ppp=0;
		}
		if(a[i]<=4){
			t[a[i]]++;
		}else{
			bbb=0;
		} 
	}
	sort(a+1,a+n+1);
	if(ppp){
		cout<<a[n-m+1];
		return 0;
	}else if(bbb){
		if(m<=t[4]){
			cout<<4;
		}else if(m<=t[3]){
			cout<<3;
		}else if(m<=t[2]+t[3]){
			cout<<2;
		}else{
			cout<<1;
		}
		return 0;
	}else if(m==1||m==2||m==n){
		if(m==1){
			cout<<a[n];
			return 0;
		}else if(m==2){
			ll ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ans=max(ans,a[i]&a[j]);
				}
			}
			cout<<ans;
			return 0;
		}else{
			int ans=a[1];
			for(int i=2;i<=n;i++){
				ans&=a[i];
			}
			cout<<ans;
			return 0;
		}
	}else{
		int ans=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

