#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,ans,a[200010],b[200010];
void s(int t,int w){
	if(t>=w) return ;
	int mid=(t+w)/2;
	s(t,mid);s(mid+1,w);
	int i=t,j=mid+1,k=t;
	while(i<=mid&&j<=w)
		if(a[i]>a[j]) b[k++]=a[i],i++;
		else b[k++]=a[j],j++;
	while(i<=mid) b[k++]=a[i],i++;
	while(j<=w) b[k++]=a[j],j++;
	for(int i=t;i<=w;i++) a[i]=b[i];
	return ;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	s(1,n);ans=a[1];
	for(i=2;i<=m;i++) ans=ans&a[i];
	cout<<ans;                  
	return 0;
}
