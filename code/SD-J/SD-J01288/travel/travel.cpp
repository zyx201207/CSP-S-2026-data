#include<bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	int r1=(s1[0]-'0')*10+(s1[1]-'0');
	int r2=(s2[0]-'0')*10+(s2[1]-'0');
	if(r1!=r2){
		cout<<"000";
		return 0;
	}
	cout<<1;
	int a1=s1[2]-'A'+1;
	int a2=s2[2]-'A'+1;
	if(a1<=3 && a2>3 || a2<=3 && a1>3){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(a1==a2+1 || a1==a2-1){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}
