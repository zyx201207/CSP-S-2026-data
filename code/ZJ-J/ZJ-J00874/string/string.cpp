#include<bits/stdc++.h>
using namespace std;
int n,i,t,w,mi;
long long s;
struct node{
	int x;
	char s;
}a[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i].x>>a[i].s;
	t=1;w=n;
	while(t<w){
		mi=min(a[t].x,a[w].x);
		if(a[t].s!=a[w].s)s+=mi;
		a[t].x-=mi;
		a[w].x-=mi;
		if(a[t].x==0)t++;
		if(a[w].x==0)w--;
	}
	cout<<s;
	return 0;
}