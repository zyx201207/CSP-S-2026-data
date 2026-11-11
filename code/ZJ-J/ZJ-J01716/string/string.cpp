#include<bits/stdc++.h>
using namespace std;
string s="";
long long n,a,cnt;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	while(n--){
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	for(int i=0;i<=s.size()/2;i++){
		int j=s.size()-i-1;
		if(s[i]!=s[j]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}