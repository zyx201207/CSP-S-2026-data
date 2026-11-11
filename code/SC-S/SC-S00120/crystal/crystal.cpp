#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		if(ans>i){
			break;
		}
		int j=i-1,t=m,cnt=1;
		while(j>=1&&t>=(a[i]-a[j])){
			t=t-(a[i]-a[j]);
			cnt++;
			j--;
		}
		if(cnt>ans){
			ans=cnt;
		}
	}
	cout<<ans;
	return 0;
}