#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;bool side[256],A1,A2,A3,A4;char next[256];
int main(){
	freopen("travel.in","r",stdin),freopen("travel.out","w",stdout),side['A']=side['B']=side['C']=1,next['A']='B',next['B']='C',next['D']='F',next['C']=next['F']='*',cin>>c1>>s1>>c2>>s2,A1=(c1==c2),A2=A1&&(s1.substr(0,2)==s2.substr(0,2)),A3=A2&&(side[s1[2]]==side[s2[2]]),A4=A3&&(s1[2]==next[s2[2]]||s2[2]==next[s1[2]]),cout<<A1<<A2<<A3<<A4;
	return 0;
}
