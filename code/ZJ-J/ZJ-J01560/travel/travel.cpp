#include<bits/stdc++.h>
using namespace std;
int flag[7]={1,1,0,0,0,0};
char c1[3],s1[4],c2[3],s2[4];
char a1[4]={'A','B','C'};
char a2[3]={'D','E'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<2;i++)cin>>c1[i];
	for(int i=0;i<3;i++)cin>>s1[i];
	for(int i=0;i<2;i++)cin>>c2[i];
	for(int i=0;i<3;i++)cin>>s2[i];
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			flag[0]=0;
			break;
		}
	}
	cout<<flag[0];
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]||flag[0]==0){
			flag[1]=0;
			break;
		}
	}
	cout<<flag[1];
	if(flag[1]==1){
		for(int i=0;i<3;i++){
			if(s1[2]==a1[i]){
				for(int j=0;j<3;j++){
					if(s2[2]==a1[j]){
						flag[2]=1;
						flag[3]=1;
						break;
					}
				}
			}
			if(flag[2]==1)break;
		}
	}
	if(flag[2]!=1&&flag[0]==1&&flag[1]==1){
		if((s1[2]=='D'&&s2[2]=='E')||(s1[2]=='E'&&s2[2]=='D'))flag[2]=1,flag[4]=1;
	}
	if(flag[2])cout<<1;
	else cout<<0;
	if(flag[2]==1){
		if(flag[3]==1){
			if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A'))cout<<0;
			else cout<<1;
		}
		if(flag[4]==1)cout<<1;
	}
	else cout<<0;
	return 0;
}
