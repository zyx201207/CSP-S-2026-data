#include<bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
//freopen("string.in","r",stdin);
//freopen("string.out","w",stdout);
int n,m;
char a;
cin>>n;
string s;
for(int i=1;i<+n;i++){
	cin>>m>>a;
	for(int i=1;i<=m;i++){
		s+=a;
	}
	if(string.size(s)%2==0&&s[s.size()/2==0]){
		cout<<0
	}
}
return 0;
}