#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if((s1[0]==s2[0])&&(s1[1]==s2[1]))	
		{
			if(((64<s1[2]&&s1[2]<68)&&(64<s2[2]&&s2[2]<68))||(67<s1[2]&&s1[2]<70)&&(67<s2[2]&&s2[2]<70)){
				if((s1[2]==s2[2]+1)||(s1[2]==s2[2]-1))
				{
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}

	return 0;
} 
