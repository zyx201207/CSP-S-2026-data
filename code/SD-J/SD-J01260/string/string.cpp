#include<bits/stdc++.h>
using namespace std;
string s1,s2;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >>n;
	long long a;
	string b;
	for(int i=0;i<=n;i++){
		cin >> a >> b;
		for(int j=0;j<a;j++){
			s1+=b;
		}
	}
	s2=s1;
	reverse(s2.begin(),s2.end());
	for(int i=0;i<s1.length()/2;i++){
		if(s1[i]!=s2[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
