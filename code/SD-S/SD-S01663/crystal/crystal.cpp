#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+505;
int n,m,a[N],ans;

signed main(){

freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}sort(a+1,a+n+1);
if(n<=5000){

for(int i=2;i<=n;i++){
	if(a[i]==a[i+1])
	continue;
	int sum=0,tot=1;
	for(int j=i-1;j>=1;j--){
		tot++;
		sum+=a[i]-a[j];
		if(sum>m){
			tot--;
			sum-=(a[i]-a[j]);
			break;
		}
	}ans=max(ans,tot);
}cout<<ans;

}else{

int h=1,t=1,sum=0;
while(t<n){
	int x=a[t+1];
	int len=t-h+1;
	sum+=(x-a[t])*len;
	while(h<=t && sum>m){
		sum-=(x-a[h]);
		h++;
	}ans=max(ans,t-h+2);
	t++;
}cout<<ans;

}

return 0;
}
