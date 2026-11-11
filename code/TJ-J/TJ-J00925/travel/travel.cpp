#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	char a=s1[2],b=s2[2];
	if((a-'A'<=2 && b-'A'<=2) || (a-'A'>=3 && b-'A'>=3)){
		cout<<1;
		if(a-'A'>=3 && b-'A'>=3){
			cout<<1;
			return 0;
		}
	}
	else{
		cout<<"00";
		return 0;
	}
	int a1=a-'A',b1=b-'A';
	if(abs(a1-b1)==1){
		cout<<1;
	}
	else{
		cout<<"0";
	}
	return 0;
}
