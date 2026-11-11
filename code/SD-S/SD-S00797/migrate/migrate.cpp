#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,zuo[150000][3]={};
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n,b,ans=0;
		cin>>n>>b;
		for(int j=0;j<n;j++)	cin>>zuo[j][0];
		if(zuo[0][0]<0)	for(int j=0;j<n;j++)	zuo[j][0]+=(0-zuo[0][0]);
		if(zuo[0][0]>0)	for(int j=0;j<n;j++)	zuo[j][0]-=zuo[0][0];
		for(int j=0;j<n;j++){
			zuo[j][1]=zuo[j][0]-1;
			zuo[j][2]=zuo[j][0]/b;
		}
		for(int j=b+1;j<n;j++){
			int r=0;
			for(int w=0;w<b;w++)	if(zuo[j][2]-1<=zuo[j-1][2]&&zuo[j][1]-1>=zuo[j-1-w][1])	r=1;
			if(r==1)	ans++;	
		}
		cout<<ans<<endl;
	}
	return 0;
}
