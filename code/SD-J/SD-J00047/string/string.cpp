#include<bits/stdc++.h>
using namespace std;
long long dp[10000005],n,cnt=1,ans;
char s[10000005];
struct st{
	long long x;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long m=n;
	while(m--){
		long long x;
		cin>>x;
		char c;
		cin>>c;
		a[n-m]={x,c};
		cnt+=x;
	}
	cnt--;
	long long l=1,r=n;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].x==a[r].x) l++,r--;
			else if(a[l].x<a[r].x) l++;
			else r--;
		}else{
			if(a[l].x==a[r].x) l++,r--,ans+=a[l-1].x;
			else if(a[l].x<a[r].x) a[r].x-=a[l].x,ans+=a[l].x,l++;
			else a[l].x-=a[r].x,ans+=a[r].x,r--;
		}
	}
	cout<<ans;
	return 0;
}
//Trick||Treat!
