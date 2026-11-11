#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
vector<int> a(5e5+5);
vector<int> v(5e5+5);
vector<int> k;
map<int,int> mp;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		v.clear();
		v=a;
		for(int j=i;j<=n;j++){
			auto it=find(v.begin()+i,v.end()+j-1,v[j]);
			if(it!=v.end()){
				for(auto k=it-v.begin();k<j;k++)v[k]=0;
			}
		}
		for(int j=i;j<=n;j++){
			mp[v[j]]++;
			
		}
	}
	for(int i=1;i<=m;i++)cout<<mp[i]<<(i==m?"":" ");
	return 0;
}
