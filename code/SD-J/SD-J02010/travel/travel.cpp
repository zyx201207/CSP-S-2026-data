#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	ll p1=(s1[0]-'0')*10+(s1[1]-'0'),p2=(s2[0]-'0')*10+(s2[1]-'0'),l1=s1[2]-'A'+1,l2=s2[2]-'A'+1;
	if(c1==c2){
		cout<<"1";
		if(p1==p2){
			cout<<"1";
			if(l1>=1&&l1<=3&&l2>=1&&l2<=3||l1>=4&&l1<=5&&l2>=4&&l2<=5){
				cout<<"1";
				if(abs(l1-l2)==1) cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
}
//AC!!!
//这肯定是个橙题 
