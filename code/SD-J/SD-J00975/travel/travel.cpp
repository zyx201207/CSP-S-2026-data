#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
#define time cerr<<"\nTime is:"<<clock()
int main(){
	fin("travel.in");
	fout("travel.out");
	cin.tie(0)->sync_with_stdio(0);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	string p1=c2;
	p1.erase(2);
	string p2=c4;
	p2.erase(2);
	char z1=c2[2];
	char z2=c4[2];
	if(c1!=c3) cout<<"0000"; 
	else{
		if(p1!=p2) cout<<"1000";
		else{
			if(z1<='C'&&z2>'C'||z1>='E'&&z2<'E') cout<<"1100";
			else{
				if(z1+1==z2&&z1!='C'||z1-1==z2&&z1!='D') cout<<"1111";
				else cout<<"1110";
			}
		}
	}
	return time,0;
}//C
