#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int l1=s1[0]*10+s1[1],l2=s2[0]*10+s2[1];
	bool f1=(s1[2]<='C'),f2=(s2[2]<='C');
	if(c1!=c2) cout<<"0000";
	else{
		if(l1!=l2) cout<<"1000";
		else{
			if(f1!=f2) cout<<"1100";
			else{
				if(abs(s1[2]-s2[2])!=1) cout<<"1110";
				else cout<<"1111";
			}
		}
	}
	return 0;
}
