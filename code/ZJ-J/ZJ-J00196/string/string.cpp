#include<bits/stdc++.h>
using namespace std;
long long n,a,x;
string s,b;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>b;
		while(a--){
			s+=b;
		}
	}
	for(long long i=0;i<=s.size()/2-1;i++){
		if(s[i]!=s[s.size()-i-1])x++;
	}
	cout<<x;
	return 0;
}