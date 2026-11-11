#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a,cnt=0;
	char c;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	long long l=s.length();
	cnt=0;
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]){
			s[l-i-1]=s[i];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
