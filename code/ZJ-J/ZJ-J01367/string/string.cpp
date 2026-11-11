#include<bits/stdc++.h>
using namespace std;
long long n,s,x,y,b,c,ans;
struct T{
	long long a;
	char c;
}a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
		s+=a[i].a;
	}
	b=1;
	c=n;
	x=a[b].a;
	y=a[c].a;
	while(b<=n&&c>=1){
		if(x>y){
			if(a[b].c!=a[c].c)ans+=y;
			x-=y;
			c--;
			y=a[c].a;
		}
		if(y>x){
			if(a[b].c!=a[c].c)ans+=x;
			y-=x;
			b++;
			x=a[b].a;
		}
		if(x==y){
			if(a[b].c!=a[c].c)ans+=x;
			b++;
			c--;
			x=a[b].a;
			y=a[c].a;
		}
	}
	cout<<ans/2;
}