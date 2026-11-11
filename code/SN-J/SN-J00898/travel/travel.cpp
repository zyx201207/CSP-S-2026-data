#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	string d1,d2,g1,g2;
	cin>>c1>>s1>>c2>>s2;
	d1=s1.substr(0,2);
	d2=s2.substr(0,2);
	if(c1==c2&&c1!="01"&&c1!="16"){
		cout<<1;
		if(d1==d2){
			cout<<1;
			g1=s1.substr(2,1);
			g2=s2.substr(2,1);
			if(abs((g1[0]-'0')-(g2[0]-'0'))<2&&abs((g1[0]-'0')-(g2[0]-'0'))!=0||g1[0]=='D'&&g2[0]=='F'||g1[0]=='F'&&g2[0]=='D'){
				if(g1[0]=='C'&&g2[0]=='D'||g1[0]=='D'&&g2[0]=='C'){
					cout<<"00";
				}
				else{
					cout<<"11";
				}
				return 0;
			}
			else{
				if(g1[0]=='A'&&g2[0]=='C'||g1[0]=='C'&&g2[0]=='A'){
					cout<<"10";
				}
				else{
					cout<<"00";
				}
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	cout<<"0000";
	return 0;
}
