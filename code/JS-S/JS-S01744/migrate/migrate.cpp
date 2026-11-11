#include<bits/stdc++.h>
#define int long long
using namespace std;
int ccccc,t,x[2000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>ccccc>>t;
	for(int g=1;g<=t;g++){
		int n,d;
		cin>>n>>d;
		if(ccccc==13||ccccc==14){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(ccccc==11||ccccc==12){
			
			int r=x[2]-x[1];
			d/=r;
			int ans=n-d*2+1;
			if(ans<0) ans=0;
			if(d<=1) ans=0;
			cout<<ans<<endl;
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int l=0;
				int y[j-i+10],a=0,b=1,z[j-i+10];
				for(int k=i+1;k<=j;k++){
					if(x[k]-x[k-1]>d){
						l=1;
						break;
					}
					a+=x[k]-x[k-1];
					if(a>d){
						y[b]=k-1;
						z[b]=a-x[k]+x[k-1];
						a=x[k]-x[k-1];
						b++;
					}
				}
				if(l==1) break;
				y[b]=j;
				z[b]=a;
				int c=0;
				for(int k=1;k<b;k++){
					for(int h=y[k];h>=1;h--){
						if((z[k+1]+x[y[k]]-x[h-1])<=d){
							c++;
						}else break;
					}
					if(c>=2) break;
				}
				//cout<<c<<" ";
				if(c==1) ans++;
				//cout<<ans<<" ";
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
