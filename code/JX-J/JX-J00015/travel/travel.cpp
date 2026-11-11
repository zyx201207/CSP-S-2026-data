#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2,s3,s4;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
        for(int i=0;i<3;i++)
        {
            if(i==0)
            {
                s3+=(s1[i]-'0')*10;
                s4+=(s2[i]-'0')*10;
            }
            else if(i==1)
            {
                s3+=s1[i]-'0';
                s4+=s2[i]-'0';
            }

        }
        if(s3==s4)
        {
            cout<<1;
            if(s1[2]>=65&&s1[2]<=67&&s2[2]>=65&&s2[2]<=67)
            {
                cout<<1;
                if(s1[2]-1==s2[2]+1||s1[2]+1==s2[2]-1)
                    cout<<0;
                else cout<<1;
            }
            else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))
            {
                cout<<"11";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
	return 0;
}
