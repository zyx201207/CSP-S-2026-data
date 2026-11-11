#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else
    {
        cout<<"0000"<<endl;
        return 0;
    }
    int line1=(s1[0]-'0')*10+(s1[1]-'0');
    int line2=(s2[0]-'0')*10+(s2[1]-'0');
    //cout<<endl<<s1<<" "<<s2<<" "<<line1<<" "<<line2<<endl;
    if(line1==line2) cout<<1;
    else{
        cout<<"000"<<endl;
        return 0;
    }
    char x1=s1[2],x2=s2[2];
    int pon1,pon2;
    if(x1=='A'||x1=='B'||x1=='C') pon1=1;
    else pon1=2;
    if(x2=='A'||x2=='B'||x2=='C') pon2=1;
    else pon2=2;
    //cout<<endl<<pon1<<" "<<pon2<<endl;//
    if(pon1!=pon2)
    {
        cout<<"00"<<endl;
        return 0;
    }
    else{
        if(pon1==2)
        {
            cout<<11<<endl;
            return 0;
        }
        cout<<1;
        bool taken[3]={};
        taken[x1-'A']=true;
        taken[x2-'A']=true;
        if((taken[0]&&taken[1])||(taken[1]&&taken[2])) cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;

}
