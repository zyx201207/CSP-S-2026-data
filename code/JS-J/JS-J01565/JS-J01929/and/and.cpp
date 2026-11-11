#include<bits/stdc++.h>
using namespace std;
int n,m,maxx;
struct nod{
	int s[35];
}a[200005];
int orz=0;
bool cmp(nod x,nod y){
	return x.s[orz]>y.s[orz];
}
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long u;
		int v=1;
		cin>>u;
		while(u!=0){
			a[i].s[v]=(u&1);
			u/=2;
			v++;
			maxx=max(maxx,v-1);
		}
	}
	int nn=n;
	for(int i=maxx;i>0;i--){
		int sum=0;
		for(int j=1;j<=nn;j++){
			if(a[j].s[i]==1){
				sum++;
			}
		}
		ans*=2;
		if(sum>=m){
			orz=i;
			sort(a+1,a+1+nn,cmp);
			nn=sum;
			ans+=1;
		}
	}
	cout<<ans;
	return 0;
}
