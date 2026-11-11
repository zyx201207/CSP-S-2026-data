#include<bits/stdc++.h>
using namespace std;
int cc,t;
int n;
long long d,x[2000010];
int w[2000010];
bool f[2000010];
long long ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>cc>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];cout<<x[i]-x[i-1]<<"\n";
			if(i>1&&x[i]-x[i-1]>d)f[i]=1;
		}
		for(int i=1;i<=n;i++){
			int l=0,q=n,z=n+1;
			w[++l]=i;
			for(int j=i+1;j<=n;j++){
				if(f[j]==1){
					q=j-1;
					break;
				}
				if(x[j]-x[w[l]]>d)w[++l]=j-1;
				if(x[j]-x[w[l]-1]<=d&&x[j]-x[w[l]-2]>d&&l>=2){
					if(z==n+1)z=j;
					else{
						q=j;
						break;
					}
				}
			}
			ans+=max(0,q-z+1);cout<<z<<"\n";
//			for(int i=1;i<=l;i++)cout<<w[i]<<" ";
//			cout<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//0 1 10 285714285714285708 -1000000000000000000 -714285714285714292 -428571428571428584 -238095238095238112 -142857142857142876 -47619047619047640 142857142857142832 428571428571428540 714285714285714248 999999999999999956

