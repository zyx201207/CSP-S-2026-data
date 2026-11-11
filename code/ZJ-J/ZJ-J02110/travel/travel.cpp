#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		int vis=0;
		for(int i=0;i<=1;i++){
			if(s1[i]!=s2[i])vis=1;
		}
		if(vis==1){
			cout<<"000";
		}
		else{
			cout<<1;
			if(s1[2]>='D'&&s2[2]>='D'){
				cout<<"00";
			}
			else if(s1[2]<='C'&&s2[2]<='C'){
				cout<<1;
				if(abs(s1[2]-s2[2])==1)cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
	}
	else {
		cout<<"0000";
	}
	return 0;
}
