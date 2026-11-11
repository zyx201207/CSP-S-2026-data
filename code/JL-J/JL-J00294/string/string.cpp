#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int l;
		char a;
		cin>>l>>a;
		for(int j=1;j<=l;j++){
			s+=a;
		}
	}
//	cout<<s<<endl;
	int cnt=0;
	for(int i=0;i<=ceil(s.size()/2);i++){
		if(s[i]!=s[s.size()-i]) cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
