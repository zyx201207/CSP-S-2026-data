#include<bits/stdc++.h> 
using namespace std;
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	string c1;
	string s1;
	string c2;
	string s2;
	int a[4];
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[0]=1;
		if(s1[0]==s2[0]){
		a[1]=1;
		if(s1[0]z<="C"&&s2]<="C"||s1[0]>="D"&&s2[0]>="D")
		a[2]=1;
		}
		
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]+1||s1[1]-1){
		a[3]=1 ;
	}
	if(s1[1]==s2[1]&&s2[0]==s2[0]+1||s1[0]-1){
		a[3]=1;
	}
	for(int i=0;i<4;i++){
		cout<<a[i];
	}
	return 0;
}
