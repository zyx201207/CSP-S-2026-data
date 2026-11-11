#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
    bool f1=(s1[2]=='D'||s1[2]=='F'),f2=(s2[2]=='D'||s2[2]=='F');
    if(c1!=c2)cout<<"0000";
    else if(s1[1]!=s2[1]||s1[0]!=s2[0])cout<<"1000";
    else if(f1&&f2)cout<<"1111";
    else if(f1&&!f2||f2&&!f1)cout<<"1100";
    else if(abs(int(s1[2]-s2[2]))==1)cout<<"1111";
    else cout<<"1110";
	return 0;
}