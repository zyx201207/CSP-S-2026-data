#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],l,r,mid,ans;
bool ch(long long x){	
		return a[x]*x-b[x]<=m;
}
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m;
l=1;
r=n;
for(int i=1;i<=n;i++){
	cin>>a[i];
	
}sort(a+1,a+n+1);
for(int i=1;i<=n;i++){
	b[i]=b[i-1]+a[i];
}
for(int i=1;i<=n;i++){

l=i,r=n;
while(l<=r){
	mid=(l+r)/2;
	if(a[mid]*(mid-i+1)-b[mid]+b[i-1]<=m){
		l=mid+1;
		ans=max(mid-i+1,ans);
	}else{
		r=mid-1;
	}
}}//cout<<b[315274]<<'\n';
cout<<ans;
	return 0;
}//Oct31==Dec25?

