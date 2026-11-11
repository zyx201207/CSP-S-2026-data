#include<bits/stdc++.h>
using namespace std;
vector<int> v;
long long ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	for(int i=1;i<=n;i++){
		bool y[300005]={0},l=0;
		int m=0;
		for(int j=0;j<v.size();j++){
			if(y[v[j]]!=0){
				v.erase(v.begin());
				l=1;
				m=j;
				break;
			}else if(!m){
				y[v[j]]=1;
			}
		}
		if(l==0) v.erase(v.begin());
		for(int j=m;j<v.size();j++){
			ans[v[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]-2<<" ";
	}
	return 0;
}
