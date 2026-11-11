#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,ai,b,bi,d;
	string c;
	cin>>a>>ai>>b>>bi;
	if(ai[0] == bi[0] && ai[1] == bi[1] && ai[2] == bi[2] && a == b){
		c = "1100";}
		if(ai[2]+1 == bi[2]){
			c = "1110";}
		else if(ai[2]-1 == bi[2]){
			c = "1110";}
		else if(ai[2]-1 != bi[2] && ai[2]+1 != bi[2]){
			c = "1100";}
	else if(ai[0] != bi[0] && ai[1] != bi[1] && ai[2] != bi[2] && a == b){
		c = "1000";
		if(ai[2]+1 == bi[2]){
			c = "1010";}
		else if(ai[2]-1 == bi[2]){
			c = "1010";}
		else if(ai[2]-1 != bi[2] && ai[2]+1 != bi[2]){
			c = "1000";}}
	else if(ai[0] != bi[0] && ai[1] != bi[1] && ai[2] != bi[2] && a != b){
		c = "0000";}
	cout<<c;
	return 0;
}
