#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
long long n;
string ans;
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	IOS;
	cin>>n;
	while(n--){
		long long x;
		string s;
		cin>>x>>s;
		for(long long i=1;i<=x;i++)ans+=s;
	}
	long long len=ans.size();
	for(long long i=0;i<=len/2;i++){
		if(ans[i]!=ans[len-i-1])sum++;
	}
	cout<<sum;
	return 0;
}
