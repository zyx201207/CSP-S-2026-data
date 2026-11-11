#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s1,s2,t1,t2;
	cin>>s1>>s2>>t1>>t2;
	bool a=0,b=0,c=0,d=0;
	if(s1==t1){
		a=1;
		if(s2[0]==t2[0] && s2[1]==t2[1]){
			b=1;
			if((s2[2]>='A' && s2[2]<='C') && (t2[2]>='A' && t2[2]<='C') || (s2[2]>='D' && s2[2]<='E') && (t2[2]>='D' && t2[2]<='E')){
				c=1;

			}
			if(s2[2]==char(t2[2]-1) || s2[2]==char(t2[2]+1)){
                d=1;
            }
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}
