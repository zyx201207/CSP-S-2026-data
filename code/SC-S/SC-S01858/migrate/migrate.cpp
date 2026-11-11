#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,T,n,d,x[N],p[N],f[501][501],r[N],g[501][501];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(c==11||c==12){
			int k=d/(x[2]-x[1]);
			if(k<=1)cout<<"0\n";
			else cout<<max(0ll,n-2*k+1)<<'\n';
		}else if(c==13||c==14){
			int k,an=0;
			for(int i=1;i<=n;i++){
				if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
					k=i;
					break;
				}
			}
			if(k==1){cout<<"0\n";continue;}
			for(int i=1;i<k;i++){
				if(k+2<=n&&x[k+2]-x[i]<=d)continue;
				int l,no=x[i]+d+1;
				if(k-2>=1)no=max(no,x[k-2]+d+1);
				l=lower_bound(x+1,x+n+1,no)-x;
				if(l>n)continue;
				if(x[k+1]-x[i]<=d){
					int tp=lower_bound(x+1,x+n+1,x[k-1]+d+1)-x;
					l=max(l,tp),an+=n-l+1;
				}else{
					int r=upper_bound(x+1,x+n+1,x[k-1]+d)-x-1;
					if(l<=r)an+=r-l+1;
				}
			}
			cout<<an<<'\n';
		}else{
			int re=0;
			memset(f,0x3f,sizeof f);
			memset(g,0,sizeof g);
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(x[j]-x[i]<=d){
						f[i][j]=g[i][j]=1;
					}
				}
			}
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(f[i][j]>f[i][k]+f[k][j]){
							f[i][j]=f[i][k]+f[k][j];
							g[i][j]=g[i][k]*g[k][j];
						}else if(f[i][j]==f[i][k]+f[k][j]){
							g[i][j]+=g[i][k]*g[k][j];
						}
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					re+=(g[i][j]==2);
				}
			}
			cout<<re<<'\n';
//			r[n]=n+1;int re=0;
//			for(int i=1;i<=n;i++){
//				for(int j=n;j>i;j--){
//					if(x[j]-x[i]<=d){
//						r[i]=j;
//						break;
//					}
//				}
//			}
//			for(int i=1;i<=n;i++)cout<<r[i]<<' ';cout<<'\n';
//			for(int i=1;i<=n;i++){
//				for(int j=i+1;j<=n;j++){
//					cout<<"i,j: "<<i<<' '<<j<<'\n';
//					int nu=0,no=i;
//					while(1){
//						if(r[no]>=j){
//							if(no!=j)p[++nu]=j;
//							break;
//						}
//						no=r[no],p[++nu]=no;
//					}
//					for(int k=1;k<=nu;k++)cout<<p[k]<<' ';cout<<'\n';
//					if(p[1]==i+1||nu==1){f[i][j]=0;continue;}
//					no=p[1]-1;
//					cout<<"no: "<<no<<' ';
//					for(int k=2;k<nu;k++)no=min(r[no],p[k]-1),cout<<no<<' ';
//					no=r[no],f[i][j]=(no==j);
//					cout<<no<<'\n';
//				}
//			}
//			for(int i=1;i<=n;i++){
//				for(int j=i+1;j<=n;j++){
//					cout<<f[i][j]<<' ';
//				}
//				cout<<'\n';
//			}
//			for(int i=1;i<=n;i++){
//				cout<<"i: "<<i<<'\n';
//				int nu=0,no=i;
//				while(1){
//					if(r[no]>=n){
//						if(no!=n)p[++nu]=n;
//						break;
//					}
//					no=r[no],p[++nu]=no;
//				}
//				for(int j=1;j<=nu;j++)cout<<p[j]<<' ';cout<<'\n';
//				int k=1,su=0;
//				for(int j=i+1;j<=n;j++){
//					int tp=su;
//					if(k<=nu&&p[k]==j){
//						for(int l=1;l<k;l++)su+=f[p[l]][p[k]];
//						k++,tp=su;
//					}else{
//						for(int l=1;l<=k;l++)tp+=f[p[l]][j];
//					}
//					if(tp==1)re++;
//				}
//			}
//			cout<<re<<'\n';
		}
	}
	return 0;
}