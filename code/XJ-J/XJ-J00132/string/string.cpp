#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
string s,x,y;
char b;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s+=' ';
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b;
		for(int j=1;j<=a[i];j++)s+=b;
	}
	long long q;
	if(s.size()%2==0)q=s.size()/2-1;
	else q=s.size()/2;
	for(long long i=1;i<=q;i++){
		if(s[i]!=s[s.size()-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
