#include<iostream>
#include<cstring>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,i,cnt,ans;
	long long a[100005];
	char b[100005];
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(i=n;i>=1;i--){
		if(b[i]==b[i-1]) cnt+=a[i]+a[i-1];
	}
	for(i=1;i<=n;i++){
		if(b[i]==b[i+1]) ans+=a[i]+a[i+1];
	}
	for(i=0;i<=n;i++){
		if(b[i+1]!=b[n-i]) ans-=cnt;
	}
	cout<<ans;
	return 0;
}
