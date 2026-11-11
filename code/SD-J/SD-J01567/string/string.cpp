#include<bits/stdc++.h >
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long n,a[200005];
	char c[200005];
	string s;
	long long sum=0,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(long long j=1;j<=a[i];j++) s+=c[i];
		sum+=a[i];
	}
	s=" "+s;
	long long l;
	if(sum%2) l=sum/2+1;
	else l=sum/2;
	for(long long i=1;i<=l;i++){
		if(s[i]!=s[sum-i+1]) cnt++;
	}
	cout<<cnt;
	return 0;
}
