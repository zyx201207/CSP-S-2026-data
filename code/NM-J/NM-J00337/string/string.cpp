#include<bits/stdc++.h>
using namespace std;
long long n,a,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	long long b=s.size();
	long long r=b-1;
	for(int i=0;i<b/2;i++){
		if(s[i]!=s[r]){
			ans++;
		}
		r--;
	}
	cout<<ans;
	return 0;
}
//为什么要演奏春日影？！！； 
