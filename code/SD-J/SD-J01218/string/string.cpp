#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,cnt,sum;
long long ans;
string s;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	s=" ";
	for(int i=1;i<=n;i++){
		int x;
		cin>>x>>c;
		for(int i=1;i<=x;i++) s+=c;
		sum+=x;
	}
	for(int i=1;i<=sum/2;i++){
		if(s[i]!=s[sum-i+1]) ans++;
	}
	cout<<ans;
	return 0;
} 
