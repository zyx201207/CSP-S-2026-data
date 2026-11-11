#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,x[2000005],mn[2000005],mx[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==13||c==14){
		while(T--){
			cin>>n>>d;
			for(int i=1;n>=i;i++)
				scanf("%lld",&x[i]);
			if(d<(x[2]-x[1])*2||x[n]-x[1]<d){
				cout<<0<<endl;
				continue;
			}
			int cnt=d/(x[2]-x[1]);
			
			cout<<n-cnt*2+1<<endl; 
		} 
		return 0;
	}
	while(T--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;n>=i;i++)
			scanf("%lld",&x[i]);
			memset(mx,0,sizeof(mx));
			memset(mn,0,sizeof(mn));
		for(int i=1;n>=i;i++){
			int l=1,r=i-1,mid,gl=0;
			while(l<=r){
				mid=(l+r)>>1;
				if(x[mid]+d>=x[i]){
					r=mid-1;
					gl=mid;
				}
				else 	
					l=mid+1;
			}
			//if(gl!=i)
			mn[gl]++;
			l=i+1,r=n,gl=0;
			while(l<=r){
				mid=(l+r)>>1;
				if(x[mid]<=d+x[i]){
					l=mid+1;
					gl=mid;
				}
				else 
					r=mid-1;	
			}
		//	if(gl!=i)
			mx[gl]++;
		}
		/*for(int i=1;n>=i;i++)
			cout<<mn[i]<<" ";
		for(int i=1;n>=i;i++)
			cout<<mx[i]<<" ";*/	
		for(int i=2;n>=i;i++){
			
			ans+=mx[i]*mn[i-1];
			//cout<<ans<<" ";
		}
		
		printf("%lld\n",ans);
	} 
	return 0;
}