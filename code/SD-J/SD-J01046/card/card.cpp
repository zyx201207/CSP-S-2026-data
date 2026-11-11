#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		//枚举每一局 
		vector<int> v;
		for(int j=i;j<=n;j++){
			//枚举每一局的情况 
			for(int k=0;k<(int)v.size();k++){
				if(v[k]==a[j]){
					int y=v.size();
					for(int l=1;l<=y-k;l++){
						v.pop_back();
					}
					break;
				}
			}
			v.push_back(a[j]);
		}
		for(int x:v){
			ans[x]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
