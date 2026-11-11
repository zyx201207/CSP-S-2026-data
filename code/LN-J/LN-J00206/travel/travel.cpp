#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >>c1>>s1>>c2>>s2;
    int a=(c1[0]-'0')*10+(c1[1]-'0');
    int b=(c2[0]-'0')*10+(c2[1]-'0');
    if(a==b)cout <<1;
    else cout <<0;
    int c=(s1[0]-'0')*10+(s1[1]-'0');
    int d=(s2[0]-'0')*10+(s2[1]-'0');
    if(c==d)cout <<1;
    else cout <<0;
    int e=s1[2]-'A';
    int f=s2[2]-'A';
    if((e<=3&&f<=3)||(e>3&&f>3))cout <<1;
    else{
        cout <<0;
        cout <<0;
        return 0;
    }
    if(abs(e-f)==1)cout <<1;
    else  cout <<0;
    return 0;
}
