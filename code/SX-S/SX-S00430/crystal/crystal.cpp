#include<bits/stdc++.h>
using namespace std;
int n;
bool isdc=1;
long long m,a[500005],ans=1,mnow,cnt,d;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n;
    cin>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(i==2) d=a[2]-a[1];
    	else if(i>2){
    		if(a[i]-a[i-1]!=d) isdc=0;
		}
	}
	if(isdc){
		for(int i=n-1;i>=1;i--){
			if(m<a[n]-a[i]) break;
			m-=(a[n]-a[i]);
			ans++;
		}
		cout<<ans;
		return 0;
	}
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
    	mnow=m;
    	cnt=1;
    	for(int j=i-1;j>=1;j--){
    		if(mnow<a[i]-a[j]) break;
    		mnow-=(a[i]-a[j]);
    		cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}