#include <bits/stdc++.h>
using namespace std;
struct s{
	int a=0;
	string s;
}a[200005];
s x,y;
int n,xx,yy;
long long l[200005],ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].s;
		l[i]=a[i].a+l[i-1];
	}
	if(n==2){
		if(a[1].s==a[2].s) cout<<"0";
		else cout<<min(a[1].a,a[2].a);
		return 0;
	}
	int k=upper_bound(l+1,l+n+1,l[n]/2)-l;
	xx=k;
	yy=k;
	x=a[xx];
	y=a[yy];
	if(l[k-1]==l[n]/2){
		x=a[--xx];
		x.a-=(l[n]%2==1);
	}else{
		y.a=l[k]-l[n]/2-(l[n]%2==1);
		x.a-=l[k]-l[n]/2;
	}
	while(x.a!=0||y.a!=0){
		if(x.s==""||y.s=="") break;
		if(x.a<y.a){
			if(x.s!=y.s) ans+=x.a;
			y.a-=x.a;
			x.a-=x.a;
		}else{
			if(x.s!=y.s) ans+=y.a;
			x.a-=y.a;
			y.a-=y.a;
		}
		if(x.a==0) x=a[--xx];
		if(y.a==0) y=a[++yy];
	}
	cout<<ans;
	return 0;
}
