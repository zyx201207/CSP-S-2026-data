#include <bits/stdc++.h> 
using namespace std;
int a,ans=0,c; 
string d[1005] ;
string s;
int main(){
	cin>>a;
	for(int i=1;i<=a;i++) {
	cin>>c>>d[i];
	if(d[i]==d[i+1]){
		ans=0;
	}
	}
	freopen("string2.in","r",stdin);
	freopen("string2.out","w",stdout);
	cout<<ans;
	return 0; 
}
