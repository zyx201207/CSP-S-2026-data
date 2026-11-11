#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,i,a[500100],cnt=1,j,caozuo,ans,forever;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==0)cout<<1;
	forever=m;
	for(i=n;i>=2;i--){	
		m=forever;
		cnt=1;
		for(j=i-1;j>=1;j--){
			if(m>0){
				if(m-a[i]+a[j]>=0){
					caozuo=a[i]-a[j];
					m-=caozuo;
					cnt++;	
				}	
			}
			else break; 
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;


}
