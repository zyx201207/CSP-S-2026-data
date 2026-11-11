#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;int a,b,c,d,x,y;
int main(){freopen("travel.in","r",stdin);freopen("travel.out","w",stdout); 
	cin>>c1>>s1>>c2>>s2;
	a=(c1[0]-'0')*10+c1[1]-'0';
	b=(s1[0]-'0')*10+s1[1]-'0';
	c=(c2[0]-'0')*10+c2[1]-'0';
	d=(s2[0]-'0')*10+s2[1]-'0';
	x=s1[2]-'A';
	y=s2[2]-'A';if(x>y)swap(x,y);
	if(a!=c){cout<<"0000";
	}else if(b!=d){cout<<"1000";
	}else if(x<=2&&y>=3){cout<<"1100";
	}else if(abs(x-y)!=1){cout<<"1110";
	}else cout<<"1111";
	return 0;
}
