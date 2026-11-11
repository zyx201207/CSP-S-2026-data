#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		string c;
		cin>>a>>c;
	    for(int j=1;j<=a;j++){
	    	s.append(c);
		}
	}
	int b=s.size()/2;
	string s1=s.substr(0,b);
	string s2=s.substr(b+1,n);
	for(int i=0;i<b;i++){
		if(s1[i]!=s2[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
