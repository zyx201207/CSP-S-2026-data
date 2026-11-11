#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	freeopen("travel.in","r",stdin);
//	freeopen("travel.out","w",stdout);
	int c1,c2,a[4];
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		a[0]=0;
	}else{
		a[0]=1;
	}
	if(s1[0]!=s2[0]){
		a[1]=0;
	}else if(s1[1]!=s2[1]){
		a[1]=0;
	}else{
		a[1]=1;
	}
	if((s1[2]=='C'||s2[2]=='D')&&(s1[2]=='D'||s2[2]=='C')){
		a[2]=0;
	}else{
		a[2]=1;
	}
	if(s1[2]+1!=s2[2]&&s1[2]-1!=s2[2]){
		a[3]=0;
	}else{
		a[3]=1;
	}
	for(int i=0;i<4;i++){
		cout<<a[i];
	}
	return 0;
} 
