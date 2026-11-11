#include<bits/stdc++.h>
using namespace std;

signed main(){

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string p1,p2,l1,l2;
	l1=s1[2],l2=s2[2];
	for(int i=0;i<2;i++){
        p1+=s1[i],p2+=s2[i];
	}
	if(c1!=c2) cout<<"0000";
	else if(s1[0]+s1[1]!=s2[0]+s2[1]) cout<<"1000";
	else if(!((l1>="D"&&l2>="D")||(l1<"D"&&l2<"D"))) cout<<"1100";
    else if((abs(l1[0]-l2[0])!=1)) cout<<"1110";
    else cout<<"1111";
	return 0;
}
