#include<bits/stdc++.h>
using namespace std;
long long x0[40]={0,1},b[200005],ans;
int a[35][35],f[200005];

bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	for(int i=2;i<=31;i++){
		x0[i]=x0[i-1]*2;
		//cout<<x0[i]<<" ";
	}
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(b+1,b+n+1,cmp);
	//cout<<"OK1"<<endl;
	for(long long i=1;i<=n;i++){
		long long x=b[i];
		for(int j=30;j>=1;j--){
			if(x>=x0[j]){
				x-=x0[j];
				a[i][j]=1;
			}
			//cout<<j;
		}
		//cout<<i<<endl;
	}
	
	//cout<<"OK2"<<endl;
	for(int i=30;i>=1;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(a[i][j]==1&&f[j]==0) cnt++; 
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(a[i][j]==0){
					f[j]=1;
				}
			}
		}
	}
	
	//cout<<"OK3"<<endl;
	for(int i=1;i<=n;i++){
		if(f[i]==0&&ans==0) ans=b[i];
		else if(f[i]==0&&ans!=0) ans=ans&b[i];
	}
	
	//cout<<"OK4"<<endl;
	cout<<ans;
	return 0;
}
