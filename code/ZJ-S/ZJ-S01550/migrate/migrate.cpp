#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=310;
int x[N],a[N][N],ff[N],f[N],p[N],fff[N];
int o,i,j,t,w,tt,st,hh,h,c,T,n,d,sum,fl,hhh,ww,k,ttt,flfl,l;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;ttt=0;sum=0;
		for(i=1;i<=n;i++){
			cin>>x[i];
			if(x[i]-x[i-1]>d||i==1)++ttt,p[ttt]++,a[ttt][p[ttt]]=x[i];
			else p[ttt]++,a[ttt][p[ttt]]=x[i];
		}
		for(o=1;o<=ttt;o++){
			for(i=1;i<p[o];i++)
			  for(j=i+2;j<=p[o];j++){
			  	t=i;w=j;h=0;hh=0;fl=1;
			  	f[++h]=i;
			  	while(t<j){
			  		tt=t;
			  		while(a[o][t+1]-a[o][tt]<=d&&t<j)
			  			t++;
			  		f[++h]=t;
				}
				ff[h]=w;hh++;
				while(w>i){
					ww=w;
					while(a[o][ww]-a[o][w-1]<=d&&w>i)w--;
					hh++;
					ff[h-hh+1]=w;
				}
				if(h!=hh)continue;
				flfl=0;
				
				for(k=1;k<h;k++)
				  if(f[k]!=ff[k]){
				  	flfl=1;hhh=0;
				  	t=f[k]-1;
				  	fff[++hhh]=t;
				  	while(t<j){
				  		tt=t;
				  		while(a[o][t+1]-a[o][tt]<=d&&t<j)
				  			t++;
				  		if(t==tt)break;
				  		fff[++hhh]=t;
					}
					for(l=k;l<h;l++)
					  if(ff[l]!=fff[l-k+1]){
					  	fl=0;
					  	break;
					  }
				  }
				  sum+=(fl&flfl);
			  }
		
		}
		for(i=1;i<=ttt;i++)p[i]=0;
		cout<<sum<<"\n";
	}
	return 0;
}