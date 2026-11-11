#include<bits/stdc++.h>
using namespace std;
long long n,m,a[514514],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long cnt=1,t=0,last=1;
	for(int i=1;i<n;i++){
		if(t+(a[i+1]-a[i])*cnt<=m){
			t+=(a[i+1]-a[i])*cnt;
			cnt++;
			ans=max(ans,cnt);
		}
		else{
			while(last<=i&&t+(a[i+1]-a[i])*cnt>m){
				t-=a[i]-a[last];
				cnt--;
				last++;
			}
			t+=(a[i+1]-a[i])*cnt;
			cnt++;
		}
	}
	cout<<ans;
	return 0;
}
