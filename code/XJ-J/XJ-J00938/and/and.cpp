#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long ans=a[n];
	int cnt=n-1;
	for(int i=m-1;i>=1;i--){
		ans=(ans&a[cnt]);
		cnt--;
	}
	cout<<ans;
    return 0;
}