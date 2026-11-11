#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;cin>>n;
	for(long long i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	
	long long i=1,j=n;
	long long ans=0;
	for(;i<=j;){
		if(c[i]==c[j]){
			long long mn=min(a[i],a[j]);
			a[i]-=mn,a[j]-=mn;
		}else{
			long long mn=min(a[i],a[j]);
			a[i]-=mn,a[j]-=mn;
			ans+=mn;
		}
		if(a[i]<=0)i++;
		if(a[j]<=0)j--;
	}
	cout<<ans;
	return 0;
}
