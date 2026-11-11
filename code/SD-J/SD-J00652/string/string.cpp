#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string s;
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n; cin>>n;
	s+=' ';
	for(int i=1;i<=n;i++){
		int a; cin>>a;
		char c; cin>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	long long len=s.size()-1;
	for(int i=1;i<=len/2;i++){
		if(s[i]!=s[len-i+1]){
			cnt++; 
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
