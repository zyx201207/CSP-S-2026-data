#include <bits/stdc++.h>
using namespace std;
struct station{
	int k,a[5010],t[5010];
}k[510];
int c,n,m,d,q,start,end,t[5010],b[5010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>t[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i].k;
		for(int j=1;j<=k[i].k;j++){
			cin>>k[i].a[j]>>k[i].t[j];
		}
	}
	int num=0;
	for(int i=1;i<=k[1].k;i++){
		for(int j=1;j<=k[2].k;j++){
			if(k[1].a[i]==k[2].a[j]){
				b[num]=k[1].a[i];
				num++;
			}
		}
	}
	while(q--){
		cin>>start>>end;
		if(n==1){
			cout<<t[start]+t[end]+k[1].t[start]+k[1].t[end];
			continue;
		}
		int a=0,b=0,f=0;
		for(int i=1;i<=k[1].k;i++){
			if(start==k[1].a[i]){
				a=1;int i1=i
			}
			if(end==k[1].a[i]) b=1;;int i2=i
			if(a=b=1) f=1;break;
		}
		for(int i=1;i<=k[2].k;i++){
			if(a=b=1) break;
			if(start==k[2].a[i]) a=2;int i1=i
			if(end==k[2].a[i]) b=2;int i2=i
			if(a=b=2) f=2;
		}
		if(f==1){
			cout<<t[start]+t[end]+k[1].t[start]+k[1].t[end]<<endl;
			continue;
		}
		if(f==2){
			cout<<t[start]+t[end]+k[2].t[start]+k[2].t[end]<<endl;
			continue;
		}
		if(a==1&&b==2){
			int ans=INT_MAX;
			for(int i=1;i<=num;i++){
				int nw=t[start]+t[end]+k[1].t[start]+k[2].t[end]+k[i1].t[i]+k[i2].t[i];
				ans=min(nw,ans);
			}
			cout<<ans<<endl;
			continue;
			
		}
		if(a==2&&b==1){
			int ans=INT_MAX;
			for(int i=1;i<=num;i++){
				int nw=t[start]+t[end]+k[2].t[start]+k[1].t[end]+k[i1].t[i]+k[i2].t[i];
				ans=min(nw,ans);
			}
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}
