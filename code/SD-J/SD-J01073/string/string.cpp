#include<bits/stdc++.h>
using namespace std;
long long n;
long long  a[200005];
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long sum=0;
	for(long long i=1;i<=n;i++) {
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
			sum++;
		}
	}
	
	long long ans=0;
	string ss=s;
	reverse(ss.begin(),ss.end());
	if(ss==s){
		cout<<0;
		return 0;
	}
	for(long long  i=1;i<=sum/2;i++){
		if(s[i]==s[sum+1-i])
		continue; 
		else {
			s[i]=s[sum+1-i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

