//郭昕宇 西安市铁一中学 SN-J00713 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mp[200005][40];
bool flag[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int a;
	for(int i=1;i<=n;i++){
		cin>>a;
		for(int j=30;j>=0;j--){
			if(a>=pow(2,j)){
				mp[i][j]=1;
				a-=pow(2,j);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=3;j>=0;j--){
//			cout<<mp[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	ll ans=0;
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(flag[j]==0)cnt+=mp[j][i];
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(mp[j][i]==0)flag[j]=1;
			}
			ans+=pow(2,i);
		}
	}
	cout<<ans;
	return 0;
}
