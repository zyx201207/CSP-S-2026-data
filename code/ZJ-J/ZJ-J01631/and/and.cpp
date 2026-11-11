#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000001],b[1000001],c[1000001],mx,mx1,mx2;
bool cmp(int a,int b){
	if(a<b)return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	mx=-1e9;
	if(m==1)mx=a[1];
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
	}
	else if(m<n){
		mx=a[1];
		mx1=a[1];
		mx2=a[1];
		for(int i=1;i<=n;i++){
			if(a[i]%2==1)b[i]=a[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i]%2==0)c[i]=a[i];
		}
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=m;i++)max(mx,mx&=b[i]);
		for(int i=1;i<=m;i++)max(mx1,mx1&=c[i]);
		for(int i=1;i<=m;i++)max(mx2,mx2&=a[i]);
		mx=max(max(mx,mx1),mx2);
	}
	else if(m==n){
		mx=a[1];
		for(int i=1;i<=n;i++)mx&=a[i];
	}
	cout<<mx;
	return 0;
}
