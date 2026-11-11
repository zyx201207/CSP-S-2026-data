#include<bits/stdc++.h>
using namespace std;
long long x[2000010];
int l[2000010],r[2000010],sl[2000010],sr[2000010],dl[2000010],dr[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		int n;
		long long d;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		int tl=1;
		for(int i=1;i<=n;i++)sl[i]=sr[i]=1,dl[i]=dr[i]=0;
		for(int i=1;i<=n;i++){
			while(tl<n&&x[tl+1]-x[i]<=d)tl++;
			r[i]=tl;
		}
		tl=n;
		for(int i=n;i>=1;i--){
			while(tl>1&&x[i]-x[tl-1]<=d)tl--;
			l[i]=tl;
		}
		for(int i=1;i<=n;i++)if(r[i]>i)dr[r[i]]++;
		for(int i=n;i>=1;i--)if(l[i]<i)dl[l[i]]++;
		for(int i=n;i>1;i--){
			if(r[i]==r[i-1]){
				sl[i]=1;
				continue;
			}
			sl[i]+=sl[r[i]]+r[i]-r[i-1]-1;
		}
		for(int i=1;i<n;i++){
			if(l[i]==l[i+1]){
				sr[i]=1;
				continue;
			}
			sr[i]+=sr[l[i]]+l[i+1]-l[i]-1;
		}
//		for(int i=1;i<=n;i++){
//			cout<<l[i]<<' '<<r[i]<<' '<<sl[i]<<' '<<sr[i]<<' '<<dl[i]<<' '<<dr[i]<<endl;
//		}
		long long ans=0;
		for(int i=1;i<n;i++){
			if(x[i+1]-x[i]>d||l[i+1]>=i||r[i]<=i+1)continue;
			int x=l[i],y=r[i+1];
			if(r[x]==i+1&&l[y]==i)ans+=1ll*(sr[x]-1)*(sl[y]-1);
			if(r[x]==i+1)ans+=1ll*(sr[x]-1)*dl[i];
			if(l[y]==i)ans+=1ll*(sl[y]-1)*dr[i+1];
			ans+=1ll*dr[i+1]*dl[i];
		}
		printf("%lld\n",ans);
//		break;
	}
	return 0;
}

