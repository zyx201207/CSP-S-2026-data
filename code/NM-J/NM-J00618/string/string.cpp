#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s=s+c;
		}
	}
	int cnt=0;
	int lg=s.size();
	int l=0,r=lg-1;
	for(int i=1;i<=lg/2;i++){
		if(s[l]!=s[r]){
			cnt++;
		}
		l++,r--;
	}
	cout<<cnt;		
	return 0;	
}
