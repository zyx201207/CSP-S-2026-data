#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[300005],f[300005];
struct l{
	int t,nt;
}p[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i].nt=-1;
	}
	p[n+1].nt=-1;
	for(int i=n;i>=1;i--){
		if(!f[a[i]]){
			p[i].t=i;
			p[i].nt=i+1;
			int j=i+1;
			while(j!=-1){
				c[p[j].t]++;
				j=p[j].nt;
			}
			f[p[i].t]=1;
		}else{
			int j=i+1;
			while(j!=-1){
				f[p[j].t]=0;
				if(p[p[j].nt].t==a[i]){
					p[p[i+1].nt].nt=i;
					break;
				}
				j=p[j].nt;
			}
			f[i]=0;
		}
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	return 0;
}
