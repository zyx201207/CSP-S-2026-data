#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)return puts("0000"),0;
    if(!(s1[0]==s2[0]&&s1[1]==s2[1]))return puts("1000"),0;
    if(!(s1[2]<='C'&&s2[2]<='C')&&!(s1[2]>='D'&&s2[2]>='D'))return  puts("1100"),0;
    if(s1[2]>s2[2]) swap(s1,s2);
    if(!(s2[2]-s1[2]==1&&s2[2]!='D')&&!(s2[2]=='F'&&s1[2]=='D'))return puts("1110"),0;
    cout<<"1111"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
