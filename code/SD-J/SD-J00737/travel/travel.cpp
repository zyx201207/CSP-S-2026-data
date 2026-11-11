#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	int ic1=(c1[0]-48)*10+(c1[1]-48);
	int ic2=(c2[0]-48)*10+(c2[1]-48);
	int is1=(s1[0]-48)*10+(s1[1]-48);
	int is2=(s2[0]-48)*10+(s2[1]-48);
	if(ic1==ic2){
		cout<<"1";
		if(is1==is2){
			cout<<"1";
			if((int(s1[2])<=67&&int(s2[2])<=67)||(int(s1[2])>67&&int(s2[2])>67)){
				cout<<"1";
				if(abs(s1[2]-s2[2])==1){
					cout<<"1";
				}
				else{
					cout<<"0";
					return 0;
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
