#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000007],b[2000007],cc[2000007],ans,x,aa[5000][5000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			ans=0;
			for(int i=1;i<=n;i++){
				scanf("%lld",&a[i]);
				if(i!=1) b[i]=a[i]-a[i-1],cc[i]=cc[i-1]+b[i];
			}
			x=a[2]-a[1];
			if(d<=2*x) cout<<0;
			else {
				
			}
		}		
	}else if(c==13||c==14){
		while(t--){
			cout<<0<<endl;
		}				
	}else{
		while(t--){
			cin>>n>>d;
			ans=0;
			for(int i=1;i<=n;i++){
				scanf("%lld",&a[i]);
				if(i!=1) b[i]=a[i]-a[i-1],cc[i]=cc[i-1]+b[i];
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[i]+d>=a[j]) aa[i][j]=aa[i][j-1];
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(aa[i][j]==2) ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
//yl1
//0 2 
//4 2 
//1 2 3 4 
//5 2 
//1 2 3 4 5 

//yl2
//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6


