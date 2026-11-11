/*

*/
#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	int cnt=0;
	if(a1 == b1){
		cout<<'1';
		cnt++;
		if(cnt==1 && a2[0]==b2[0] && a2[1]==b2[1]){
			cnt++;
			cout<<'1';
		}else{
			cout<<'0';
		}
		if(cnt==2 && ((a2[2]>'C' && b2[2]>'C') || (a2[2]<'D' && b2[2]<'D'))){
			cnt++;
			cout<<'1';
		}else{
			cout<<'0';
		}
		if(cnt==3 && (a2[2]==b2[2]-1 || a2[2]-1==b2[2])){
			cout<<'1';
		}else{
			cout<<'0';
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
