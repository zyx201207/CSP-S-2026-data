#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int a[5]={};
char c1[5],s1[5],c2[5],s2[5];
cin>>c1>>s1>>c2>>s2;
if(c1[0]==c2[0]&&c1[1]==c2[1]){
	a[0]=1;
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		a[1]=1;
		if(s1[2]<=67&&s2[2]<=67||s1[2]>=68&&s2[2]>=68){
			a[2]=1;	
			if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
				a[3]=1;
			}
			else{
				a[3]=0;
				}
		}
		else{
			a[2]=0;
			a[3]=0;
		}
	}
	else{
		a[1]=0;
		a[2]=0;
		a[3]=0;
	}
}
else{
	a[0]=0;
	a[1]=0;
	a[2]=0;
	a[3]=0;
}
for(int i=0;i<4;i++){
	cout<<a[i];
}
return 0;
}
