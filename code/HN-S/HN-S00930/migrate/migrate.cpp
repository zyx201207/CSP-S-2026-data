#include<bits/stdc++.h>
using namespace std;
long long z,t,n,d,a[100005],b[100005],c[100005],sum,w1,w2;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>z>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i-1]=a[i]-a[i-1];
		}
		for(int i=1;i<=n;i++){
			c[i]=c[i-1]+b[i-1];
		}
		for(int i=1;i<n;i++){
			for(int j=i;j<=n;j++){
				if (c[j]-c[i]>d && c[j]-c[i]-b[i]<=d && c[j]-c[i]-b[j-1]<=d){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}
