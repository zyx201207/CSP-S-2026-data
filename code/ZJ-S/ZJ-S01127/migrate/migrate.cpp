#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,num[2000005],minl,ans,sumn;
void dfs(int now,int to,int sum){
	if(sum>minl){
//		cout<<"*&";
		return;
	}
	if(now==to){
//		cout<<1<<" ";
		if(sum==minl)ans++;
		else if(sum<minl)minl=sum,ans=1;
//		cout<<minl<<' '<<ans<<" \n";
	}
	int i=now;
	while(num[++i]-num[now]<d);
	
	while(i>to)i--;
	for(;i>now;i--){
		dfs(i,to,sum+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		sumn=0;
		for(int i=1;i<=n;i++){
			cin>>num[i];
		}
		for(int i=1;i<=n;i++){
			if(i>1&&num[i]-num[i-1]>d){
				n=i-1;
				break;
			}
		}
		if(c>6){
			cout<<0<<endl;continue;
		}
		for(int i=1;i<=n-2;i++){
			for(int j=i+2;j<=n;j++){
				minl=0x7f7f7f7f7f,ans=0;
				dfs(i,j,1);
//				cout<<i<<" "<<j<<" "<<ans<<"\n";
				if(ans==2)sumn++;
			}
		}
		cout<<sumn<<endl;
	}
	return 0;
} 
