#include<bits/stdc++.h>
using namespace std;
int a[10000],cnt,mx=-99999;
int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=n=1;i>=2;i--){
		cnt=0;
		for(long long j=n-1;j>=2;j--){
			cnt+=a[n]-a[i];
			cout<<j<<endl;
			if(cnt>m){
				break;
			}else{
				mx=j;
			}
		}
	}
	cout<<mx;
	return 0;
}
