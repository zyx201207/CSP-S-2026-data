#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int n,d;
bool pd(int x,int y){
	
	int s=0,k=d;
	bool f=0;
	for(int i=x;i<=y;i++){
		if(k>=a[i]-a[i-1]&&i!=x){
			k-=(a[i]-a[i-1]);
		}
		else{
			k=d;
		}
		s=a[i+1]-a[i]+a[i+2]-a[i+1];
		
		if(s<=d&&i<=y-2){
			f=1;
		}
	}
	cout<<x<<' '<<y<<' '<<k<<endl;
	if(f&&k==d){
		return 1;
	}
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		int sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(pd(i,j)){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
