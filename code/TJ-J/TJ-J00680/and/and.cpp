#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],c[200010],pre[200010],minn=INT_MAX,ml,mr,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=m;i<=n;i++){
		if(a[i]-a[i+1]<minn){
			minn=a[i]-a[i+1];
			ml=i-m+1;
			mr=i;
		}
	}
	ans=a[ml];
	for(int i=ml+1;i<=mr;i++){
		ans=(ans&a[i]);
	}
	cout<<ans;
	return 0;
}
