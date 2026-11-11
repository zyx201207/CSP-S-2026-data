#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int x1=(s1[0]-'0')*10+s1[1]-'0',x2=(s2[0]-'0')*10+s2[1]-'0';
	int y1=s1[2]-'A',y2=s2[2]-'A';
	bool T=1;
	if(c1==c2) cout<<1;
		cout<<0;
		T=0;
	}
	if(x1==x2&&T) cout<<1;
	else{
		cout<<0;
		T=0;
	}
	if(y1<=2&&y2<=2&&T || y1>=3&&y2>=3 &&T) cout<<1;
	else{
		cout<<0;
		T=0;
	}
	if(abs(y1-y2)==1&&T) cout<<1;
	else cout<<0;
	 
	return 0;
}
