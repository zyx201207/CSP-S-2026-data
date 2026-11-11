
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> a;
int pkset[5000005];
int m;
vector<int>amap;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int pk=1;pk<=n;pk++){
	
	for(int c=pk;c<=n;c++){
		for(auto &k:pkset){
			if(k==a[c]){
				k=0;
				continue;
			}
		}
		pkset[c]=a[c];
		
	}
}
	for(auto k:pkset){
		amap[k]++;
	}
	for(int i=1;i<=n;i++){
		cout<<amap[i]<<' ';
	}
	
	return 0;
}
