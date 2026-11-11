#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool flag[4]={1,1,1,1};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		flag[0]=false;
		flag[1]=false;
		flag[2]=false;
		flag[3]=false;
		if((s1[0]-'0')*10+(s1[1]-'0')*10!=(s2[0]-'0')*10+(s2[1]-'0')*10){
			flag[1]=false;
			flag[2]=false;
			flag[3]=false;
			if(!((s1[2]-'A'<3&&s2[2]-'A'<3)||(s1[2]-'A'>2&&s2[2]-'A'>2))){
				flag[2]=false;
				flag[3]=false;
				if(abs((s1[2]-'A')-(s2[2]-'A'))!=1&&((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C'))){
					flag[3]=false;
				}
			}
		}
	}
	if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
		flag[3]==1;
	}
	for(int i=0;i<4;i++){
		cout<<flag[i];
	}
	return 0;
} 
