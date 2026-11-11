#include<bits/stdc++.h>
using namespace std;
long long cnt=500,c,n,m,d,q,k2,ans;
long long a[500500];
struct node{
	long long f; 
	long long z[25],s[25];//z线路,s时间 
	long long next[25];
}w[500500];
int minn(int h,int r){
	long long ys=1000000;
	for(int i=1;i<=min(w[h].f,w[r].f);++i){
		if(w[h].z[i]!=0 && w[i].z[i]!=0){
			ys=min(ys,w[h].s[w[h].z[i]]+w[r].s[w[r].z[i]]);
			cout<<ys<<endl;
		}
	}
	return ys;
}
void search(int b,int c){
	if(b==c){
		ans=min(ans,cnt);
		return;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		int u;
		cin>>u;
		k2=0;
		for(int j=1;j<=u;++j){
			long long k,l;
			cin>>k>>l;
			w[k].f++;
			w[k].z[w[k].f]=i;
			w[k].s[w[k].f]=l;
			w[k2].next[i]=k;
			k2=k;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=0;
		ans+=a[x];
		ans+=a[y];
		ans+=minn(x,y);
		cout<<ans<<endl;
	}
	fclose(stdin);
	return 0;
}
