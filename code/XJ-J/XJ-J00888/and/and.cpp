#include <bits/stdc++.h>
using namespace std;
long long n,m,cnt,x,y,z;
long long a[200005];
long long b[200005],c[200005];
long long max1=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cnt=1;
	y=1;
	x=1;
	z=1;
	while(cnt!=0){
		b[y]=a[]/2;
		c[x]=
		while(b[y]!=0){
			y++;
			b[y]=b[y-1]/2;
			c[x]=b[y]
		}
			
		cnt=a[i]%2;
	}
	return 0;
	
	
}