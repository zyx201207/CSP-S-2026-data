#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans=0;
bool c[31][200010];
vector<int> used[31];
vector<int> da;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=30;j>=0;j--){
			if(a[i]&(1<<j)){
				c[j][i]=1;
				used[j].push_back(i);
			}
		}
	}
	for(int i=30;i>=0;i--){
		if(used[i].size()>=m){
			if(!da.size()){
				for(auto j:used[i]){
					da.push_back(j);
				}
				ans+=(1<<i);
			}else{
				vector<int> ad;
				for(auto j:da){
					if(c[i][j]) ad.push_back(j);
				}
				if(ad.size()>=m){
					da=ad;
					ans+=(1<<i);
				}
			}
		}
	}
	cout<<ans;
}
