#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long int a[N],b[N];
vector<long long int> g[31];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int k=0;
		while(a[i]>>k){
			if((a[i]>>k)&1){
				g[k].push_back(a[i]);
			}
			k++;
		}
	}
	int id=0;
	for(int i=30;i>=0;i--){
		if(g[i].size()>=m){
			id=i;
			break;
		}
	}
	bool b1=1;
	while(g[id].size()>m && b1==1){
		int l=g[id].size(); 
		for(int i=0;i<l;i++){
			b[i]=g[id][i];
		}
		for(int i=30;i>=0;i--){
			g[i].clear();
		}
		for(int i=0;i<l;i++){
			int k=0;
			while(b[i]>>k){
				if((b[i]>>k)&1){
					g[k].push_back(b[i]);
				}
				k++;
			}
		}
		b1=0;
		for(int i=id-1;i>=0;i--){
			if(g[i].size()>=m){
				b1=1;
				id=i;
				break;
			}
		}
	}		
	long long int ans=g[id][0];
	for(int i=1;i<m;i++){
		ans&=g[id][i];
	}	
	cout<<ans;
	return 0;
}
