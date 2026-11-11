#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
    int aa,bb,cc,dd;
    if(c1[0]-'0'==c2[0]-'0'&&c1[1]-'0'==c2[1]-'0') aa=1;
    else{
    	cout<<"0000"<<endl;
    	return 0;
	}
	if(s1[0]-'0'==s2[0]-'0'&&s1[1]-'0'==s2[1]-'0') bb=1;
	else{
		cout<<"1000"<<endl;
		return 0;
	}
	if((s1[2]-'a'+32>=3)&&(s2[2]-'a'+32>=3)){
		cout<<"1111"<<endl;
		return 0;
	} 
    if((s1[2]-'a'+32<=2)&&(s2[2]-'a'+32<=2))cc=1;
    else{
    	cout<<"1100"<<endl;
    	return 0;
	}
    if(abs((s1[2]-'a')-(s2[2]-'a'))==1)cout<<aa<<bb<<cc<<"1"<<endl;
    else cout<<"1110"<<endl;
	return 0;
}

