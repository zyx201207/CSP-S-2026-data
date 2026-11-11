#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int l;
		char c;
		cin>>l>>c;
		for(int j=1;j<=l;j++){
			s+=c;
		}
	}
	int len=s.size()/2;
	s=' '+s;
	int j=len*2+1;
	for(int i=1;i<=len;i++){
		if(s[i]!=s[j]){
			cnt++;
		}
		j--;
	}
	cout<<cnt;
	return 0;
}
