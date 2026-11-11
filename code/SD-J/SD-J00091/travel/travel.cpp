#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	for(int i=1;i<=17;i++){
		if(c1!=c2){
			cout<<0;
			break;
		}
		else{
			cout<<1;
			break;
		}
	}
	for(int i=1;i<=17;i++){
		if(s1!=s2){
			cout<<0;
			break;
		}
		else{
			cout<<1;
			break;
		}
	}
	for(int i=1;i<=17;i++){
		if(s1!=s2){
			cout<<0;
			break;
		}
		else{
			cout<<1;
			break;
		}
	}
	for(int i=1;i<=17;i++){
		if(s1!=s2){
			cout<<0;
			break;
		}
		else{
			cout<<1;
			break;
		}
	}
	return 0;
}
//02 01A 02 01B
