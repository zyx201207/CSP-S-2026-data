#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
string a,a1,b,b1;
	cin>>a>>a1>>b>>b1;
	if(a==b) cout<<"1";
	else cout<<"0";
	if(a1[0]==b1[0]&&a1[1]==b1[1]) cout<<"1";
	else cout<<"0";
	if(abs(int (a1[2]-b1[2]))==1){
		cout<<"1"<<"1";
	}else if(a1[2]>=65&&a1[2]<=67&&b1[2]>=65&&b1[2]<=67) cout<<"1"<<"0";
	else cout<<"0"<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
