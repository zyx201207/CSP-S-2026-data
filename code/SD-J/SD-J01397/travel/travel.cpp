#include<bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
using namespace std;
string c1,c2,s1,s2;
ll a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=(c1[0]-'0')*10+c1[1]-'0';
	b=(c2[0]-'0')*10+c2[1]-'0';
	a=a*1000+(s1[0]-'0')*100+(s1[1]-'0')*10+(s1[2]-'A');
	b=b*1000+(s2[0]-'0')*100+(s2[1]-'0')*10+(s2[2]-'A');
	if(a/1000==b/1000){
		cout<<1;
		if(a/10==b/10){
			cout<<1;
			if((a%10<3&&b%10<3)||(a%10>2&&b%10>2)){
				cout<<1;
				if(abs(a%10-b%10)==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
