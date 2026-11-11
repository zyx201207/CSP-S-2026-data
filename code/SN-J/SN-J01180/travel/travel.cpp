#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace Vesperon{
	string c1,s1,c2,s2;
	void chek(){
		if(c1==c2){
			cout<<1;
			if(s1[0]==s2[0]&&s1[1]==s2[1]){
				cout<<1;
				if((s1[2]=='C'&&s2[2]=='D')||(s2[2]=='C'&&s1[2]=='D')){
					cout<<"00";
				}
				else{
					if(s1[2]>='D'||s2[2]>='D'){
						if(abs(s1[2]-s2[2])==1){
							cout<<"11";
						}
						else{
							cout<<"00";
						}
					}
					else{
						if(abs(s1[2]-s2[2])==1){
							cout<<"11";
						}
						else{
							cout<<"10";
						}
					}
				}
			}
			else{
				cout<<"000";
			}
		}
		else{
			cout<<"0000";
		}
	}
	void work(){
		freopen("travel.in","r",stdin);
		freopen("travel.out","w",stdout);
		cin>>c1>>s1>>c2>>s2;
		chek();
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	return Vesperon::work() ,0;
}
