#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[1000001];
int ans;
int l=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		m-=((i-l)*(a[i]-a[i-1]));
		while(m<0){
			m+=(a[i]-a[l]);
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
}
