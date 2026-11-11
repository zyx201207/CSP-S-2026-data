#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=5e5+5;
int a[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	map<int,int> mp1;
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			map<int,int> mp;
			vector<int> v;
			if(!mp.count(a[i])){
				v.push_back(a[i]);
				mp[a[i]]++;
			}
			else{
				mp.clear();
				int pos=0;
				for(int k=0;k<i;k++){
					if(v[k]==a[i]) pos=k;
				}
				int num=v.size()-pos;
				while(num--){
					v.pop_back();
				}
				v.push_back(a[i]);
			}
			for(auto j=0;j<v.size();j++){
				mp1[v[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mp1[i]<<' ';
	}
	return 0;
}
