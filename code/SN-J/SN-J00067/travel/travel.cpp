#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool b[4];
	if(c1==c2){
		b[1]=true;
	}else{
		b[1]=false;
	}
	for(int i=0;i<2;i++){
		if(b[1]!=0 and s1[i]==s2[i]){
			b[2]=true;
		}else{
			b[2]=false;
		}
	}
	for(int i=2;i<3;i++){
		if(b[2]==0 or s1[i]=='D' and s2[i]=='C' or s1[i]=='C' and s2[i]=='D'){
			b[3]=false;
			b[4]=false;
		}else{
			if(b[2]!=0){
				b[3]=true;
			}
		}
	}
	for(int i=2;i<3;i++){
		if(b[3]!=0 and s1[i]+1==s2[i]+0 or s1[i]-1==s2[i]+0 and b[3]!=0){
			b[4]=true;
		}else{
			if(b[3]==0){
				b[4]=false;
			}
		}
	}
	for(int i=1;i<=4;i++){
		cout<<b[i];
	}
	return 0;
}
