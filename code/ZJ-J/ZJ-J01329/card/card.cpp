#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
int cnt[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		vector<int> v;
		for(int j=i;j<=n;j++){
			int pos=0;
			for(int k=0;k<v.size();k++){
				if(a[j]==v[k]){
					pos=k;
					break;
				}
			}
			if(pos){
				int len=v.size();
				for(int k=pos;k<len;k++){
					v.pop_back();
				}
			}
			v.push_back(a[j]);
		}
		
		for(int j=0;j<v.size();j++){
			cnt[v[j]]++;
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}