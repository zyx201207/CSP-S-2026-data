#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5;
array<int,N>a;
deque<int>dq;
map<int,int>mp;
int n,m;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			for(int j=0;j<(int)dq.size();j++){
				int ind;
				if(dq[j]==a[i]){
					ind=dq.size()-j;
					while(ind--){
						dq.pop_back();
					}
					break;
				}
			}
			dq.push_back(a[i]);
		}
		for(int i=0;i<(int)dq.size();i++){
			//TODO
			mp[dq[i]]++;
		}
		dq.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<mp[i]<<" ";
	}
	return 0;
}
