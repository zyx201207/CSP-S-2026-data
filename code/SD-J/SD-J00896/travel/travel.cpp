#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]!=c2[0]||c1[1]!=c2[1]){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s1[0]+s1[1]==s2[0]+s2[1]&&s1[0]==s2[0]){
		cout<<1;
		int a=s1[3],b=s2[3];
		if(((b<'D'&&(b==a||b-a==1||b-a==2))||(b<='F'&&(b==a||b-a==1)))){
			cout<<1;
			if(a>b){
				swap(a,b);
			}
			if(b<='C'&&b-a==1||b<='F'&&b-a==1){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<"00";
		}
	}else{
		cout<<"000";
	}
	return 0;
}
//Trick||Treat!
