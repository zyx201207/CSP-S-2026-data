#include<bits/stdc++.h>
using namespace std;
long long a[200005];
string b[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(long long i=0;i<n;i++){
		for(long long j=0;j<a[i];j++){
			s+=b[i];		
		}
	}
	long long cnt=s.size()-1,sum=0;
		for(long long i=0;i<s.size()/2;i++){
		if(s[sum]!=s[cnt]){
			ans++;
		}
		sum++;
		cnt--;
	}
	cout<<ans;
	return 0;
}
