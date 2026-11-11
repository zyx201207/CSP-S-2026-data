#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],x,y,cnt,sx,sy,l,r,s;
char c[500005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>c[i];
	}
	x=1;y=n,sx=a[1],sy=a[n],s=min(a[1],a[n]);
	while(x<y){
		if(c[x]!=c[y]) cnt+=s;
		if(sx>sy){
			y=y-1;
			s=min(a[y],sx-sy);
			sy+=a[y];
		}else if(sx<sy){
			x=x+1;
			s=min(a[x],sy-sx);
			sx+=a[x];
		}else{
			y=y-1;
			x=x+1;
			s=min(a[y],a[x]);
			sx+=a[x];
			sy+=a[y];
		}
	}
	printf("%lld",cnt);
	return 0;
} 
