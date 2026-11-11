#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,sum;
int ans;
long long a[N];
long long b[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)b[i]=a[i+1]-a[i];
	for(int i=2;i<=n;i++)a[i]=a[i-1]+b[i-1];
	for(int i=n;i>=1;i--){
		for(int j=i-1;j>=1;j--){
			sum=a[i]-a[j];
			if(sum<=m)ans=max(ans,i-j+1);
		}
	}
	cout<<ans;
    return 0;
}
