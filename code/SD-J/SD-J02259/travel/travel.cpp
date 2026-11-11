#include<bits/stdc++.h>//jm99
#define endl '\n'//jm99
#define ll long long //jm99
using namespace std;//jm99
string  c1,s1,c2,s2,x,y,a,b;//jm99
int main(){//jm99
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);//jm99
	freopen("travel.in","r",stdin);//jm99
	freopen("travel.out","w",stdout);//jm99
	cin>>c1>>s1>>c2>>s2;//jm99
	for(int i=0;i<2;i++){//jm99
		x+=s1[i];//jm99
		y+=s2[i];//jm99
	} //jm99
	a=s1[2],b=s2[2];//jm99
	if(c1==c2){//jm99
		cout<<"1";//jm99
		if(x==y){//jm99
			cout<<"1";//jm99
			if(a=="A"&&b=="B"||a=="B"&&b=="C"||a=="D"&&b=="F"||a=="B"&&b=="A"||a=="C"&&b=="B"||a=="F"&&b=="D")cout<<"11";//jm99
			else if(a=="A"&&b=="C"||a=="C"&&b=="A")cout<<"10";//jm99
			else cout<<"00";//jm99
		}//jm99
		else cout<<"000";//jm99
	}//jm99
	else cout<<"0000";//jm99
    return 0;//jm99
}//jm99
