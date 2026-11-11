#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			int x=s1[2]-'A',y=s2[2]-'A';
			if((x>=0&&x<=2&&y<=2&&y>=0)||(x>=3&&x<=5&&y>=3&&y<=5)){
				cout<<1;
				if(x==0&&y==1||x==1&&y==0||x==2&&y==1||x==1&&y==2||x==3&&y==5||x==5&&y==3){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";

	return 0;
}
