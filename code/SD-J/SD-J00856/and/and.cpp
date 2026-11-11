#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10,C=30;
int n,m,a[N],vis[N],ans;
int main(){
	//freopen("and5.in","r",stdin);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int k=30;k>=0;k--){
		vector<int>s;
		int RP=1<<k,sz=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				if(a[i]&RP){
					sz++;
					continue;
				}
			}
			s.push_back(i);
		}
		if(sz>=m){
			ans+=RP;
			for(int i:s){
				vis[i]=1;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
