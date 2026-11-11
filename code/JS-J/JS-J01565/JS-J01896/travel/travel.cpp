#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2;
    int a,b;
    cin>>a>>s1>>b>>s2;
    if(a==b)
        cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    int x=0,y=0;
    for(int i=0;i<2;i++)
    {
        x=x*10+s1[i]-'0';
    }
     for(int i=0;i<2;i++)
    {
        y=y*10+s2[i]-'0';
    }
    if(x==y)
        cout<<1;
    else
    {
        cout<<"000";
        return 0;
    }
    char c=s1[2],d=s2[2];
    if(((c=='A'||c=='B'||c=='C')&&(d=='A'||d=='B'||d=='C'))||((c=='D'||c=='F')&&(d=='D'||d=='F')))
        cout<<1;
    else
    {
        cout<<"00";
        return 0;
    }
    int xx=abs(c-d);
    if(xx==1) cout<<1;
    else cout<<0;
    return 0;
}
