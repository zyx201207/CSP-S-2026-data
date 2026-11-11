#include<bits/stdc++.h>
using namespace std;
string c[5];
bool k[5]={0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	 cin>>c[1]>>c[2]>>c[3]>>c[4];
	 //cout<<c[1]<<" "<<c[2]<<" "<<c[3]<<" "<<c[4];
	 if(c[1]==c[3]){
		 k[1]=1;
		if(c[2][0]==c[4][0]&&c[2][1]==c[4][1]){
			k[2]=1;
			if(((c[2][2]=='A'||c[2][2]=='B'||c[2][2]=='C')&&(c[4][2]=='A'||c[4][2]=='B'||c[4][2]=='C'))||((c[2][2]=='D'||c[2][2]=='F')&&(c[4][2]=='D'||c[4][2]=='F'))){
					k[3]=1;
					int x=c[2][2]-'A';
					int y=c[4][2]-'A';
					if(abs(x-y)==1||(c[2][2]=='D'&&c[4][2]=='F')||(c[4][2]=='D'&&c[2][2]=='F')){
						k[4]=1;
					}
			}
		}
	 }
	 cout<<k[1]<<k[2]<<k[3]<<k[4]<<endl;
	return 0;
}
