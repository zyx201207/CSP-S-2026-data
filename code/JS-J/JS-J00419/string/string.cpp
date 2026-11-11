#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
char b[N];
long long su=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;
	string s;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		su+=a[i];
		for(long long j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	long long t=su-1;
	for(long long i=0;i<su;i++){
		if(i==t){
			break;
		}
		if(s[i]!=s[t]){
			ans++;
		}
		t--;
	}
	cout<<ans;
	return 0;
}
