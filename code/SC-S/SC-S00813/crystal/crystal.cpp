#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],ans=0;
double s=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	s=(s+m)/n;
	sort(a+1,a+n+1);
	//cout<<s<<endl;
	int b=lower_bound(a+1,a+n+1,s)-a-1;
	if(s-a[b]>a[b+1]-s){
		b++;
	}
	// cout<<b<<endl;
	for(int i=b;i>=1;i--){
		if(a[i]<=a[b]&&m-a[b]+a[i]>=0){
			ans++;
			m-=a[b]-a[i];
		}
	}
	int j=b+1;
	while(a[j]==a[b]){
		ans++;
		j++;
	}
	cout<<ans;
}