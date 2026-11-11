#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c[2],x[2],y[2];
    for(int i=0;i<2;i++)
    {
        string c1,s1;
        cin>>c1>>s1;
        c[i]=(c1[0]-'0')*10+c[1]-'0';
        x[i]=(s1[0]-'0')*10+s1[1]-'0';
        y[i]=s1[2]-'A';
    }
    if(c[0]==c[1])
    {
        cout<<"1";
    }
    else{
        cout<<"0000"<<endl;
        return 0;
    }
    if(x[0]==x[1])
    {
        cout<<"1";
    }
    else{
        cout<<"000"<<endl;
        return 0;
    }
    if((y[0]>=0&&y[1]<=2)||(y[0]>=3&&y[1]<=4))
    {
        cout<<"1";
    }
    else{
        cout<<"00"<<endl;
        return 0;
    }
    if(abs(y[0]-y[1])==1)
    {
        cout<<"1"<<endl;
    }
    else{
        cout<<"0"<<endl;
        return 0;
    }
    return 0;
}