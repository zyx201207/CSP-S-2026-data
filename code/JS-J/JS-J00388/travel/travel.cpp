#include<bits/stdc++.h>
using namespace std;
string a2,b2;
int a1,b1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    cout<<(a1==b1);
    int a=(a2[0]-'0')*10+a2[1]-'0',b=(b2[0]-'0')*10+b2[1]-'0';
    cout<<(a==b);
    char x=a2[2],y=b2[2];
    cout<<((x=='A'&&(y=='B'||y=='C'))||(x=='B'&&(y=='A'||y=='C'))||(x=='C'&&(y=='A'||y=='B'))||(x=='D'&&y=='F')||(x=='F'&&y=='D'));;
    cout<<((x=='A'&&y=='B')||(x=='B'&&y=='C')||(x=='B'&&y=='A')||(x=='C'&&y=='B')||(x=='D'&&y=='F')||(x=='F'&&y=='D'));
    return 0;
}
//my luogu username is OOOOOymq121218 and uid is 1624321.qiu guan zhu,bi hui guan.
//qizhongkaoshi RP++
//neng bu neng shang qi pa kao sheng xing wei da shang
//☭
