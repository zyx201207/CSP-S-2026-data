#include<bits/stdc++.h>
using namespace std;
long long n,m;
int ans;
long long a[500500];
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+1+n);
	long long cnt=0;
	int mark=1;
	for(int i=2;i<=n;i++){
		cnt+=1LL*(i-mark)*(a[i]-a[i-1]);
		//cout<<mark<<endl;
		while(cnt>m){
			cnt=cnt-a[i]+a[mark];
			mark++;
		}
		ans=max(ans,i-mark+1);
	}
	cout<<ans;
	return 0;
}
