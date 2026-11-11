#include<bits/stdc++.h>
using namespace std;
long long n,m,b,x,ans;
bool a[200010][35],c[35],d[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b;
		for(int j=1;b>0;j++){a[i][j]=b%2;b=b/2;}
	}
	for(int i=32;i>=1;i--){
		x=0;
		for(int j=1;j<=n;j++){
			if(d[j]==1)continue;
			else x=x+a[j][i];
		}
		if(x<m)continue;
		else{
			c[i]=1;
			for(int j=1;j<=n;j++){
				if(d[j]==1)continue;
				else{
					if(a[j][i]==0)d[j]=1;
				}
			}
		}
	}
	x=1;
	for(int i=1;i<=32;i++){ans=ans+x*c[i];x=x*2;}
	cout<<ans;
	return 0;
}