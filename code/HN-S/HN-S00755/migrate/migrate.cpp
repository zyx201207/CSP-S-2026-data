#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[1000005],R[1000005],dis[1000005],DIS[1000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1; i<=n; i++) cin>>a[i];
		if(n==1){cout<<"0\n";continue;}
		for(int i=1; i<=n; i++){
			R[i]=max(R[i-1],i);
			while(R[i]<=n&&a[R[i]]-a[i]<=d) R[i]++;
			R[i]--;
		}
		if(c==11||c==12){
			if(R[1]<=2){cout<<"0\n";continue;}
			cout<<max(0ll,n-2*(R[1]-1)+1)<<'\n';continue;
		}
		else if(c==13||c==14){
			int val1=0,val2=0,pos=0;
			for(int i=1; i<=n; i++) if(R[i]==n){pos=i;break;}
			for(int i=1; i<=n; i++) if(R[i]>pos) break;else val1++;
			if(pos==1||R[1]!=pos){cout<<"0\n";continue;}
			else if(pos==2){
				if(R[1]==3) cout<<n-3+n-R[pos-1]<<'\n';
				else cout<<n-R[pos-1]<<'\n';
			}
			else{
				val2=R[R[1]-1]-R[R[1]-2];
				cout<<val1*val2+n-R[pos-1]<<'\n';
			}
			continue;
		}
		// cout<<'\n';
		int ans=0;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++) dis[j]=(int)1e18,DIS[j]=0;
			dis[i]=0,DIS[i]=1;
			int nw=i;
			for(int j=i+1; j<=n; j++){
				for(int k=nw; k>=max(nw-2,i); k--){
					if(R[k]<j) break;
					if(dis[j]>dis[k]+1) dis[j]=dis[k]+1,DIS[j]=DIS[k];
					else if(dis[j]==dis[k]+1) DIS[j]=min(DIS[j]+DIS[k],3ll);
				}
				if(R[nw]==j) nw=R[nw];
				if(R[j]==j) break;
			}
			for(int j=i+1; j<=n; j++) if(DIS[j]==2) ans++;//,cout<<i<<' '<<j<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}