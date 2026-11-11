#include<bits/stdc++.h>
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Dor(i,x,y) for(int i=x;i>=y;i--)
#define ll long long
using namespace std;
string c1,s1,c2,s2;
bool check(string s){
	if(s[2]=='A' || s[2]=='B' || s[2]=='C')
		return true;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	int a1=c1[0]*10+c1[1],b1=s1[0]*10+s1[1];
	int a2=c2[0]*10+c2[1],b2=s2[0]*10+s2[1];
	if(a1==a2){
		cout<<"1";
		if(b1==b2){
			cout<<"1";
			if(check(s1) && check(s2) || (!check(s1) && !check(s2))){
				cout<<"1";
				if(abs(s1[2]-s2[2])==1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}