#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2,s;


int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    int a1=(s1[0]-'0')*10+s1[1]-'0',a2=(s2[0]-'0')*10+s2[1]-'0';
    if(c1==c2)s=s+'1';
    else{
        s=s+'0';
        s=s+'0';
        s=s+'0';
        s=s+'0';
        cout<<s;
        return 0;

    }
    if(a1==a2)s=s+'1';
    else {
        s=s+'0';
        s=s+'0';
        s=s+'0';
        cout<<s;
        return 0;
    }
    if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))s=s+'1';
    else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))s=s+'1';
    else {
        s=s+'0';
        s=s+'0';
        cout<<s;
        return 0;
    }
    if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='c'))||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))s=s+'1';
    else s=s+'0';
    cout<<s;
    return 0;
}
/*freopen
()/[]/{}
return 0
quanju/jubu
endl->\n
int->ll
*/
