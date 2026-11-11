#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=2e5+5;
int n,m,i,ans,a[N];
vector<int> id;
vector<int> nw;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(i=29;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if((a[j]>>i)&1){
				id.push_back(j);
				cnt++;
			}
		}
		if(cnt<m) id.clear();
		else{
			ans+=(1<<i);
			break;
		}
	}
	i--;
	for(;i>=0;i--){
		if((int)id.size()<m) break;
		int cnt=0;
		for(int k=0;k<(int)id.size();k++){
			int j=id[k];
			if((a[j]>>i)&1){
				nw.push_back(j);
				cnt++;
			}
		}
		if(cnt<m) nw.clear();
		else{
			int count=0;
			vector<int> cf;
			vector<bool> vis((int)id.size());
			for(int j=0;j<(int)nw.size();j++){
				for(int k=0;k<(int)id.size();k++){
					if(!vis[k]&&nw[j]==id[k]){
						count++;
						cf.push_back(id[k]);
						vis[k]=true;
						break;
					}
				}
			}
			if(count>=m){
				id=cf;
				ans+=(1<<i);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

