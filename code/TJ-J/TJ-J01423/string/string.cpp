#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int i=1,j=n,ans=0;
	while(i<j){
		if(c[i]!=c[j]) ans+=min(a[i],a[j]);
		if(a[i]<a[j]) a[j]-=a[i],a[i]=0,i++;
		else if(a[i]>a[j]) a[i]-=a[j],a[j]=0,j--;
		else a[i]=a[j]=0,i++,j--;
	}
	cout<<ans;
	return 0;
}
