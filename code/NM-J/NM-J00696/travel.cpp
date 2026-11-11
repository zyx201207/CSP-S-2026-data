#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int x=3,y=1;
	if(c1!=c2) cout<<"0000";
	else{
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
		else{
			y=0;
			cout<<0;
		}
		if(((s1[2]-s2[2]<=2 && s1[2]-s2[2]>0)||(s2[2]-s1[2]<=2 && s2[2]-s1[2]>0))&&y==1) cout<<1;
		else{
			if(s1[2]=='D'&&s2[2]=='F'&&y==1) cout<<1;
			if(s1[2]=='F'&&s2[2]=='D'&&y==1) cout<<1;
			else{
				cout<<0;
			}
		}
		if((s1[2]-s2[2]==1||s2[2]-s1[2]==1)&&y==1){
			if(s1[2]=='C'&&s2[2]=='D'){
				cout<<0;
				x=0;
			} 
			if(s1[2]=='D'&&s2[2]=='C'){
				cout<<0;
				x=0;
			}
			else{
				cout<<1;
			}
		}
		else{
			if(s1[2]=='F'&&s2[2]=='D'&&y==1){
				cout<<1;
				x=1;
			} 
			if(s1[2]=='D'&&s2[2]=='F'&&y==1){
				cout<<1;
				x=1;
			}
		}
		if(x==3) cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
