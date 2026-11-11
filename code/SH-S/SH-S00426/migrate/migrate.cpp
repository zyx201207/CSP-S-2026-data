#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
const int N=2e6+1;
long long x[N];
int nex[N],pre[N];
bool inpl[N];
int nitnpl[N],snitnpl[N];
int hi3n3p[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			int u=x[i]+d;
			int l=i,r=n;
			int mid;
			while(l<=r){
				mid=(l+r)>>1;
				if(u>x[mid]) r=mid-1;
				else l=mid+1;
			}
			nex[i]=l;
			u=x[i]-d;
			l=1,r=i;
			while(l<=r){
				mid=(l+r)>>1;
				if(u<=x[mid]) r=mid-1;
				else l=mid+1;
			}
			pre[i]=l;
			if(nex[i]>i&&pre[nex[i]]==i-1) inpl[i]=true;
		}
		int sum=0;
		for(int i=n;i>=1;i--){
			if(nex[i]>i){
				if(inpl[nex[i]]) snitnpl[i]=nitnpl[nex[i]]+1,nitnpl[i]=1;
				else{
					nitnpl[i]=nitnpl[nex[i]]+1;
					snitnpl[i]=snitnpl[nex[i]]+1;
				}
				sum+=snitnpl[i]-nitnpl[i];
				if(nex[nex[i]]>nex[i]){
					int fir,las;
					int l=nex[i],r=nex[nex[i]];
					int mid;
					while(l<=r){
						mid=(l+r)>>1;
						if(pre[mid]==nex[i]) r=mid-1;
						else l=mid+1;
					}
					las=r;
					l=nex[i],r=nex[nex[i]];
					while(l<=r){
						mid=(l+r)>>1;
						if(pre[mid]<nex[i]-1) l=mid+1;
						else r=mid-1;
					}
					fir=l;
					if(fir<=las&&pre[nex[i]-1]==i) hi3n3p[i]=hi3n3p[nex[i]]*(nex[i]==0)+las-fir+1;
					sum+=las-nex[i]+1+hi3n3p[nex[i]]*(nex[i]==0);
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
