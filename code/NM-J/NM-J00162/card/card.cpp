#include<bits/stdc++.h>
using namespace std;
const int NN=5*1e5+10;
const int MM=3*1e5;
int n,m;
int a[NN];
int ans[MM];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(ans,0,sizeof(ans));
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	int temp=n;
	vector<int> now;
	while(temp--){
		for(int i=n-temp;i<=n;++i){
			bool flag=0;
			if(now.size()==0){
				now.push_back(a[i]);
			}else {
				for(int j=0;j<now.size();++j){
					if(now[j]==a[i]){
						for(int k=j;k<now.size();++k){
							now[k]=0;
						}
						break;
					}
				}
				now.push_back(a[i]);
			}
		}
		for(auto v:now){
			ans[v]++;
		}
		now.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
    return 0;
}

