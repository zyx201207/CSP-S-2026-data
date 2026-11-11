#include<bits/stdc++.h>
using namespace std;
int n,t,x;
int a[200005][40],y,b[200005],f[200005];
int sum[40],m,sl,ff=1;
long long da,ly;
void c(int w){
	for(int i=1;i<=n;i++){
		if(a[i][w]==0){
			if(sl==t){
				ff=0;
				break;
			}
			f[i]=1;
			for(int j=n;j>=1;j--){
				sum[j]-=a[i][j];
			}
			sl--;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++)	cin>>b[i];
	sort(b+1,b+n+1);
	sl=n;
	for(int i=1;i<=n;i++){
		while(b[i]>0){
			a[i][++y]=b[i]%2;
			sum[y]+=b[i]%2;
			b[i]/=2;
		}
		if(y>m){
			m=y;
		}
		y=0;
	}
	for(int i=m;i>=1;i--){
		if(sum[i]>=t){
			c(i);
		}
	}
	for(int i=n;i>=1;i--){
		if(sum[i]>=t){
			ly=pow(2,i-1);
			da=da+ly;
		}
	}
	cout<<da;
	return 0;
}