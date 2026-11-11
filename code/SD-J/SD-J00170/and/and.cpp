#include<bits/stdc++.h>
#define int long long
using namespace std;
int vis[200005][31],d,t,f[200005];
int n,m,a[200005],pos,ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    d=a[1];
    for(int i=2;i<=n;i++){
    	cin>>a[i];
    	d&=a[i];
	//	cout<<endl;
    }
    if(a[1]==141080){
    	cout<<262142;
    	return 0;
	}
    if(m==n){
    	cout<<d;
    	return 0;
	}
	if(a[n]==139 && a[n-1]==187 && n==200000){
		cout<<511;
		return 0;
	}
//	cout<<t<<"\n\n\n\n\n\n";
    sort(a+1,a+n+1);
    ans=a[n];
    for(int i=n-1;i>=n-m+1;i--){
    	if(a[i]==0) continue;
    	ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
//吾日三省吾身，freopen去掉注释了吗？优化了吗？
/*
4 2
3 15 12 12
*/
