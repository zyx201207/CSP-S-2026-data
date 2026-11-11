#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int cnt1,pos1,cnt2,pos2,z1,z2,flag1,flag2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		cnt1=cnt1*10+(c1[i]-'0');
		cnt2=cnt2*10+(c2[i]-'0');
		pos1=pos1*10+(s1[i]-'0');
		pos2=pos2*10+(s2[i]-'0');
	}
	z1=s1[2]-'A'+1,z2=s2[2]-'A'+1;
	if(cnt1==cnt2){
		cout<<"1";
		if(pos1==pos2){
			cout<<"1";
			if((z1<=3&&z2<=3)||(z1>=4&&z2>=4)){
				cout<<"1";
				if(abs(z1-z2)==1)	cout<<"1";
				else cout<<"0";
			}	
			else cout<<"00";
		}
		else cout<<"000";
	}
	else	cout<<"0000";


	return 0;
}
//g++ travel.cpp -o travel
//.\travel
