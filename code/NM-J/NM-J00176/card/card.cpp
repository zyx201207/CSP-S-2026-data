#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m,card[N];
vector<int> cur;
map<int,int> ans;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>card[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int x=0;x<cur.size();x++){
				if(cur[x]==card[j]){
					cur.erase(cur.begin()+x,cur.end());
				}
			}
			cur.push_back(card[j]);
		}
		for(int j=0;j<cur.size();j++){
			ans[cur[j]]++;
		}
		cur.clear();
	}
	for(auto i:ans){
		cout<<i.second<<" ";
	}
	return 0;
}
