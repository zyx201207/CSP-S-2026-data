#include<bits/stdc++.h>
using namespace std;
string cs1,s1,cs2,s2;
bool vis1[10]={1,1,1},vis2[10];
int main(){
	//ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cs1>>s1>>cs2>>s2;
	vis2[3]=1,vis2[4]=1;
	if(cs1==cs2){
		cout<<"1";
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<"1";
			if(vis1[s1[2]-'A'] && vis1[s2[2]-'A'] || vis2[s1[2]-'A'] && vis2[s2[2]-'A']){
				cout<<"1";
				if(abs(s1[2]-s2[2])==1){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000"; 
	}
	else cout<<"0000";
	return 0;
}
