#include <bits/stdc++.h>
using namespace std;
struct st{
	int z;
	bool f;
};
int a[500005];
int c[300005];
int ans[300005];
vector<st> b;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,pre;
	cin>>n>>m;
	bool fl=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(c,0,sizeof(c));
		for(int j=i;j<=n;j++){
			int s=b.size();
			for(int k=0;k<s;k++){
				if(b[k].z==a[j]&&b[k].f==0){
					for(int l=k;l<s;l++){
						b[l].f=1;
						c[b[l].z]=0;
					}
					break;
				}
			}
			b.push_back({a[j],0});
			c[a[j]]++;
		}
		b.clear();
		for(int i=1;i<=m;i++) if(c[i]) ans[i]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}