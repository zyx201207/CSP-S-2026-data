#include<bits/stdc++.h>
using namespace std;
int c,t,n,d=0;
int x[10];
int a[10];
int b[10];
int ans[1000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		x[0]=0;
		b[0]=0;
		for(int j=1;j<n;j++){
			a[j]=x[j+1]-x[j];
			b[j]=a[j]+b[j-1];
		}
		if(n=4&&b[2]<=d&&b[3]>d&&(b[3]-b[1])<=d) ans[i]++;
		else if(n=5){
			if(b[2]<=d&&b[3]>d&&(b[3]-b[1])<=d){
			ans[i]++;
			if((b[4]-b[2])>d) ans[i]++;
			}
			if((b[3]-b[1])<=d&&(b[4]-b[1])>d&&(b[4]-b[2])<=d){
			ans[i]++;
			if(b[2]>d) ans[i]++;
			}
		}
	}
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
