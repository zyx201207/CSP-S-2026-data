#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;int a[4]={0,0,0,0},adu[2]={0,0};
	cin>>c1>>s1>>c2>>s2;
	adu[0]=s1[2];
	adu[1]=s2[2];
	if(c1[0]==c2[0] and c1[1]==c2[1]){
		a[0]=1;
	}
	if(a[0]==1 and s1[0]==s2[0] and s1[1]==s2[1]){
		a[1]=1;
	}
	if(a[1]==1){
		if((adu[0]<='C' and adu[1]<='C') or (adu[0]>='D' and adu[1]>='D')){
			a[2]=1;
		}
	}
	if(a[2]==1 and (adu[0]==adu[1]+1 or adu[0]==adu[1]-1)){
		a[3]=1;
	}
    cout<<a[0]<<a[1]<<a[2]<<a[3];
    return 0;
}
