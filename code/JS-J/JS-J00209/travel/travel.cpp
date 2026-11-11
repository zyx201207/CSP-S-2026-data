#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("travel1.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string s;
    cin>>s;
    int c1=(s[0]-'0')*10+s[1]-'0';

    cin>>s;
    int s1=(s[0]-'0')*10+s[1]-'0';
    char n1=s[2];

    cin>>s;
    int c2=(s[0]-'0')*10+s[1]-'0';

    cin>>s;
    int s2=(s[0]-'0')*10+s[1]-'0';
    char n2=s[2];

    if(c1==c2)cout<<1;
    else cout<<0;

    if(c1==c2&&s1==s2)cout<<1;
    else cout<<0;

    if(c1==c2&&s1==s2&&((n1<='C'&&n2<='C')||(n1>='D'&&n2>='D')))cout<<1;
    else cout<<0;

    if(abs(n1-n2)==1&&c1==c2&&s1==s2&&((n1!='C'&&n2!='D')||(n1!='D'&&n2!='C')))cout<<1;
    else cout<<0;
    return 0;
}
