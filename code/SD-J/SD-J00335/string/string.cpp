#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
string s=" ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
 		int x;
 		string y;
 		cin>>x>>y;
 		while(x--) s+=y;
	}
	//cout<<s;
	for(int i=1;i<=n/2+1;i++){
		if(s[i]!=s[n-i+2]) cnt++;
		cout<<cnt<<endl;
	}
	cout<<cnt;
	return 0;
}
