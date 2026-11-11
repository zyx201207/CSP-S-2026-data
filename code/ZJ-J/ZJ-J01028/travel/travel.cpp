#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c1,c2,p1,p2,k1,k2,f1,f2,f3,f4;
string s1,s2;
bool ff1(ll a,ll b){
	if(a>b) swap(a,b);
	if(a<=2&&3<=b) return false;
	return true;
}
bool ff2(ll a,ll b){
	if(a>b) swap(a,b);
	if(b-a==1) return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(ll i=0;i<s1.size();i++){
		if('0'<=s1[i]&&s1[i]<='9'){
			p1=p1*10+s1[i]-'0';
		}else{
			k1=s1[i]-'A';
		}
	}
	for(ll i=0;i<s2.size();i++){
		if('0'<=s2[i]&&s2[i]<='9'){
			p2=p2*10+s2[i]-'0';
		}else{
			k2=s2[i]-'A';
		}
	}
	f1=((c1==c2)?1:0);
	f2=((f1&&p1==p2)?1:0);
	f3=((f2&&ff1(k1,k2))?1:0);
	f4=((f3&&ff2(k1,k2))?1:0);
	cout<<f1<<f2<<f3<<f4<<"\n";
	return 0;
}
