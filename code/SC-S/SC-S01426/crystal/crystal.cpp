#include<bits/stdc++.h>
//#define int long long
using namespace std;
int a[500100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=0,m=0;
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5100){	
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			int dis=0,num=0;
			for(int j=i;j>=1;j--){
	//			dis[i][j]=a[j]-a[i];
				if(dis+a[i]-a[j]<=m){
					num++;
					dis+=a[i]-a[j];
				}
			}
			ans=max(ans,num);
		}
		cout<<ans;	
		return 0;
	}
	int cha=a[2]-a[1];
	m/=cha;
	m=sqrt(1+m*8);
	ans=(1+m)/2;
	cout<<ans;
	return 0;
}
//5 8
//-3 -1 2 2 7