//SN-J00756 程谟然 西安建筑科技大学附属中学
#include<bits/stdc++.h>
using namespace std;
bool corn[4]={0,0,0,0};
bool indep=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		corn[0]=1;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&corn[0]==1){
		corn[1]=1;
	}
	if(corn[1]==1){
		if(s1[2]=='D'&&s2[2]=='F'){
			corn[2]=1;
		}else if(s1[2]=='F'&&s2[2]=='D'){
			corn[2]=1;
		}else if(s1[2]=='B'&&s2[2]=='A'){
			corn[2]=1;
		}else if(s1[2]=='B'&&s2[2]=='C'){
			corn[2]=1;
		}else if(s1[2]=='A'&&s2[2]=='B'){
			corn[2]=1;
		}else if(s1[2]=='C'&&s2[2]=='B'){
			corn[2]=1;
		}else if(s1[2]=='A'&&s2[2]=='C'){
			corn[2]=1;
			indep=1;
		}else if(s1[2]=='C'&&s2[2]=='A'){
			corn[2]=1;
			indep=1;
		}
	}
	if(corn[2]==1&&indep!=1){
		corn[3]=1;
	}
	for(int i=0;i<=3;i++){
		cout<<corn[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
