#include<bits/stdc++.h>
using namespace std;
#define long long
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>c2>>s1>>s2;
    char c3,s3;
    for(int i=0;i<2;i++)
    {
        if(c1[i]!=s1[i])
        {
            cout<<"0000";
            return 0;
        }
        else if(c2[i]!=s2[i])
        {
            cout<<"1000";
            return 0;
        }
        for(int j=2;j<=2;j++)
        {
            c3=c2[j];
            s3=s2[j];
        }
    }
    cout<<"11";
    if(c3=='E'&&s3!='D')
    {
        cout<<"00";
        return 0;
    }
    else if(c3=='D'&&s3!='E')
    {
        cout<<"00";
        return 0;
    }
    else if(s3=='D'&&c3!='E')
    {
        cout<<"00";
        return 0;
    }
    else if(s3=='E'&&c3!='D')
    {
        cout<<"00";
        return 0;
    }
    cout<<"1";
    if(c3=='D'&&s3=='E')
    {
        cout<<"1";
    }
    else if((c3=='E'&&s3=='D'))
    {
        cout<<"1";
    }
    else if((c3=='A'&&s3=='B'))
    {
        cout<<"1";
    }
    else if((c3=='B'&&s3=='C'))
    {
        cout<<"1";
    }
    else
    {
       cout<<"0";
    }
    return 0;
}
