#include<bits/stdc++.h>
using namespace std;
long long c1,c2;
char s1[105],s2[105];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1;
	for(int i=1;i<=3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=1;i<=3;i++){
		cin>>s2[i];
	}
	if(c1==c2){
		cout<<"1";
		if(s1[1]==s2[1]&&s1[2]==s2[2]){
			cout<<"1";
			if((s1[3]<='C'&&s2[3]<='C')||(s1[3]>='D'&&s2[3]>='D')){
				cout<<"1";
				if(s1[3]+1==s2[3]||s2[3]+1==s1[3]){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
