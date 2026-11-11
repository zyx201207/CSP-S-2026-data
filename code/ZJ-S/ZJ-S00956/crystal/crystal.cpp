#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	long long i=1,j=1,cnt=0;
	while(j<=n){
		j++;
		cnt+=(j-i)*b[j];
		while(i<=j&&cnt>m){
			cnt-=a[j]-a[i];
			i++;
		}
		ans=max(ans,j-i+1);	
	}
	cout<<ans;
	return 0;
}
