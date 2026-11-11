#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans=0;
int l,r;
int a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i];
	cin>>c[i];
}
l=1,r=n;
while(l<r){
	if(a[l]<=0)l++;
	if(a[r]<=0)r--;
	if(l==r)break;
	int x=min(a[l],a[r]);
	if(c[l]!=c[r]){
		ans+=x;
	}
	a[l]-=x;
	a[r]-=x;
}
cout<<ans;
return 0;
} 

