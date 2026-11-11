#include<bits/stdc++.h>
using namespace std;
struct xxx{
	long long x;
	char c;
}a[200010];
int main()
{
 	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
	long long ans=0,n,h=1,t=0,y;
	scanf("%d",&n);
	t=n;
	for(int i=1;i<=n;++i)
		scanf("%d %c",&a[i].x,&a[i].c);
	while(h<t){
		y=min(a[h].x,a[t].x);
		if(a[h].c!=a[t].c){
			ans+=y;
		}
		a[h].x-=y;
		a[t].x-=y;
		if(a[h].x==0)	h++;
		if(a[t].x==0)	t--;
		if(h>=t)	break;
	}
	cout<<ans;
 	return 0;
}
