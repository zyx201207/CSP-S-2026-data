#include<bits/stdc++.h>
using namespace std;
const int mn=2e6+5;
long long C,T;
long long n,d,gc,gcgc,x[mn],mind,tot,cnt;
void dfsa(long long cs,long long wz,long long s,long long e){
	if(wz==e){
		mind=min(mind,cs);
		return;
	}
	for(int i=wz+1;i<=e;i++){
		if(x[i]-x[wz]>d) break;
		dfsa(cs+1,i,s,e);
	}
}
void dfsb(long long cs,long long wz,long long s,long long e){
	if(wz==e){
		if(cs==mind){
			cnt++;
		}
		return;
	}
	for(int i=wz+1;i<=e;i++){
		if(x[i]-x[wz]>d) break;
		dfsb(cs+1,i,s,e);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		if(n<=9){
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			for(long long i=1;i<n;i++){
				for(long long j=i+1;j<=n;j++){
					mind=9191;
					dfsa(0,i,i,j);
					dfsb(0,i,i,j);
					if(cnt==2){
						tot++;
					}cnt=0;
				}
			}
			cout<<tot<<"\n";
			tot=0;
		}else{
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			gc=x[2]-x[1];
			gcgc=gc/d;
			if(gcgc>=2){
				cout<<max(n-2*gcgc+1,0LL)<<"\n";
			}else{
				cout<<0<<"\n";
			}
		}
	}
	return 0;
}
