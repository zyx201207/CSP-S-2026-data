#include<bits/stdc++.h>
using namespace std;

int main(){
	string c1,s1,c2,s2,l1,l2;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<"0000";
	else{
		cout<<"1";//chexiang
		l1=s1[0]+s1[1];
		l2=s2[0]+s2[1];
		if(l2!=l1)cout<<"000";
		else{
			cout<<"1";//pai
			if(s1[2]>='A' && s1[2]<='C'){
				if(s2[2]>'C')
					cout<<"00";
				else{
					cout<<"1";//lin
					if(s1[2]==s2[2]+1 || s1[2]==s2[2]-1)
						cout<<"1";
					else cout<<"0";
				}
			}
			else{
				if(s2[2]<='C')
					cout<<"00";
				else {
					cout<<"1";
					if(s1[2]==s2[2]+1 || s1[2]==s2[2]-1)
						cout<<"1";
					else cout<<"0";
				}
				
			}
		}
	}
	return 0;
}
