#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int n,m;
int power[501000];
int vis[5000100],dis[500000];
int tt[500000];
int maxn=-1*INT_MAX,minn=INT_MAX,c=INT_MAX,ans;
bool cmp(bool x,bool y){
	return x>y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>power[i];
		vis[power[i]]++;
	}
    sort(power+1,power+n+1);
	for(int i=1;i<=n;i++){
		int tot=m;
		if(power[i+1]==power[i]&&i+1<=n){
			continue;
		}
		ans=0;
		for(int j=i;j>=1;j--){
			if(power[i]-power[j]<0){
				continue;
			}
			tot=tot-(power[i]-power[j]);
			if(tot<0){
				continue;
			}
			ans++;
		}
	    maxn=max(ans,maxn);	
	}//310825 315275 313312    63
	//5 8
    //-3 -1 2 2 7
	cout<<maxn;
}

