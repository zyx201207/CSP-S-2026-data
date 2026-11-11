#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,f;string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s1>>s2>>s3>>s4;e=s2[2];f=s4[2];if (e<f) swap(e,f);
	a=(s1[0]-'0')*10+(s1[1]-'0');b=(s2[0]-'0')*10+(s2[1]-'0');
	c=(s3[0]-'0')*10+(s3[1]-'0');d=(s4[0]-'0')*10+(s4[1]-'0');
	if (a==c){
		cout<<'1';
		if (b==d){
			cout<<'1';
			if ((e<=67&&f<=67)||(e>=68&&f>=68)){
				cout<<'1';
				if (e-f==1) cout<<'1';
				else cout<<'0';
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
}
