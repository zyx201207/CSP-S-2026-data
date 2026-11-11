#include<bits/stdc++.h>

using namespace std;
long long c,t,a[100001],q[100001];int b[2000001];
int n,d;
int vvv(int x,int y){
		if(y==0||y==1){
			return 0;
		}
		else{
			int ans=0;
			for(int i=1;i<=x-1;i++){
				for(int j=i+1;j<=x;j++){
					int h=j-i;
					if(h>y&&h<2*y){
						ans++;
					}
				}
			}
			return ans;
		}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>b[j];
		}
		q[i]=b[2]-b[1];
		d=d/q[i];
		a[i]=vvv(n,d);
	}
	for(int i=1;i<=t;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}
