#include<bits/stdc++.h>
using namespace std;
long long n,sum;
long long a;
char c;
string s1,s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	while(n--){
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	bool flag=true;
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			flag=false;
			sum++;
		}
	}
	//cout<<s;
	if(flag) cout<<0<<endl;
	cout<<sum;
	return 0;
}
