#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

const int N=5000005;

ll n,m,a[N],vis[N],del[N],tot[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	
	for(int s=1;s<=n;++s){
		for(int i=s;i<=n;++i){
			if(vis[a[i]]){
				for(int j=vis[a[i]];j<i;++j) del[j]=true;
			}
			vis[a[i]]=i;
		}
		for(int i=1;i<=n;++i){
			if(!del[i]) tot[a[i]]++;
		}
	}
	
	for(int i=1;i<=m;++i) cout<<tot[i]<<" ";
	
	return 0;
}
