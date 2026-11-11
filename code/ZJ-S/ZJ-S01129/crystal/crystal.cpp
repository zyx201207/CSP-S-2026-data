#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],ss[500010],ma,w,t,i,b[500010];
void s(int t,int w){
	int i,mid,j,k;
	if(t==w)return ;
	mid=(t+w)/2;
	s(t,mid);s(mid+1,w);
	i=t;j=mid+1;k=t;
	while(i<=mid&&j<=w)
		if(a[i]<a[j])b[k++]=a[i],i++;
		else b[k++]=a[j],j++;
	while(i<=mid)b[k++]=a[i],i++;
	while(j<=w)b[k++]=a[j],j++;
	for(i=t;i<=w;i++)a[i]=b[i];
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	s(1,n);
	for(i=1;i<=n;i++)ss[i]=ss[i-1]+a[i];
	t=w=1;
	while(t<=n&&w<=n){
		while(a[w]*(w-t+1)-(ss[w]-ss[t-1])<=m&&w<=n)w++;
		w--;
		ma=max(ma,w-t+1);
		t++;
	}
	cout<<ma;
	return 0;
}
