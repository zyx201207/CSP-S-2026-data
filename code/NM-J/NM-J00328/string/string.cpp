#include<bits/stdc++.h>
using namespace std;
string s="";
int cnt,n;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	int m;
		char ch;
    	cin>>m>>ch;
    	for(int j=1;j<=m;j++){
    		s+=ch;
		}
	}
	for(int i=0;i<=(s.length()-1)/2;i++){
		if(s[i]!=s[s.length()-1-i])
			cnt++;
	}
	cout<<cnt;
    return 0;
}
