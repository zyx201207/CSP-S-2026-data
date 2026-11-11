#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,d;
	int a[100005],b[100005],u,v,ans=0,sum=0;
	for(int i=1;i<=t;i++){
	    cin>>n>>d;
		for(int i=1;i<=n;i++){
		    cin>>a[i];
	    }
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]-a[j]<=d){
				a[i]=u;
				a[j]=v;
				for(int k=1;k<=d;k++){
					ans=u+v;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]-a[j]<=d){
				a[i]=u;
				a[j]=v;
				for(int k=1;k<=d;k++){
					sum=u+v+1;
				}
			}
		}
	}
	cout<<ans<<endl<<sum;
	return 0;
}
