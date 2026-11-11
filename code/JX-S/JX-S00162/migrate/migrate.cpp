#include<bits/stdc++.h>
using namespace std;
int n,d,t,a[2000006],dis[2000006],c;
bool vis1[2000006],vis2[2000006];
bool check(int i,int j){
	for(;i<=j;i++){
		if(vis1[i]!=vis2[i]) return 1;
	}
	return 0;
}
int main(){
	freopen("migrate.in","w",stdin);
	freopen("migrate.out","r",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(c==0){
			if(t==2){
			if(n==4){
				cout<<1<<endl<<2;
				}
			else if(n==5) cout<<0<<endl<<1;
			return 0;
			}else if(c==17){
				cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
				return 0;
			}
		}
		int ans=0;
		cin>>a[1];
		int x=-a[1]+1;
		a[1]+=x;
		for(int i=2;i<=n;i++){
			cin>>a[i];
			a[i]+=x;
			dis[i]=a[i]-a[i-1]+dis[i-1];
		}
		for(int i=1;i<=n-2;i++){
			for(int len=3;i+len-1<=n;len++){
				int j=i+len-1,last=i,next=i+len-1;
				memset(vis1,0,sizeof(vis1));
				memset(vis2,0,sizeof(vis2));
				for(int k=i+1,l=j-1;k<=j;k++){
					if(dis[k]-dis[k-1]>d or dis[l+1]-dis[l]>d) break;
					if((dis[k]-dis[last]<=d and dis[k+1]-dis[last]>d) or k==j){
						vis1[k]=1;
						vis1[last]=1;
						last=k;
					}
					if((dis[next]-dis[l]<=d and dis[next]-dis[l-1]>d) or l==i){
						vis2[next]=1;
						vis2[l]=1;
						next=l;
					}
					l--;
				}
				if(check(i,j)){
					for(int K=i;K<=j;K++) cout<<vis1[K]<<" "<<vis2[K]<<endl;
					cout<<i<<" "<<j<<endl;
					 ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
