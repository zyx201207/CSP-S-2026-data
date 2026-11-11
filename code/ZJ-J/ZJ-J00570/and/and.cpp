#include<bits/stdc++.h>
using namespace std;
int n,m,x,ans=0;
vector<int> v,v1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		v1.push_back(x);
	}
	for(int i=30;i>=0;i--){
		for(auto j:v1){
			if(j&(1<<i)){
				v.push_back(j);
			}
		}
		if((int)(v.size())>=m){
			ans+=(1<<i);
			v1=v;
		}
		v.clear();
	}
	cout<<ans;
	return 0;
}

