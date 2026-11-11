#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define int long long
#define pb push_back
const int mo=1e9+7;
ll mod(ll x){
	return (x%mo+mo)%mo;
}
const int N=0;
string s1,ss1,s2,ss2;
bool check1(){
	if(ss1[2]<='C'&&ss1[2]>='A'&&ss2[2]<='C'&&ss1[2]>='A')
	 	return 1;
	if(ss1[2]<='F'&&ss1[2]>='D'&&ss2[2]<='F'&&ss1[2]>='D')
		return 1;
	return 0;	 
}
bool check2(){
	char a=ss1[2],b=ss2[2];
	if(a>b) swap(a,b);
	if(a+1==b) return 1;
	if(a=='D'&&b=='F') return 1;
	return 0;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s1>>ss1>>s2>>ss2;
	if(s1==s2){
		cout<<"1";
		if(ss1[0]==ss2[0]&&ss1[1]==ss2[1]){
			cout<<"1";
			if(check1()){
				cout<<"1";
				if(check2())cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}else cout<<"0000";
	return 0;
}

