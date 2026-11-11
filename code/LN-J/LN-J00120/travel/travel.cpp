#include<bits/stdc++.h>
using namespace std;
int n,m,l,r;//n,r,c  m,l,s
char c,s;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>r>>c>>m>>l>>s;
    if(n!=m)
    cout<<"0000";
    else
    {
        cout<<1;
        if(r!=l)
        cout<<"000";
        else
        {
            cout<<1;
            if(((c==s-1||c==s+1)&&(!(c=='C'&&s=='D')))||((c=='C'&&s=='A')||(c=='A'&&s=='C')))
            {
                cout<<1;
                if(s=='F')
                {
                    if(c=='D')
                    cout<<1;
                    else
                    cout<<0;
                }
                else if(s=='D')
                {
                    if(c=='F')
                    cout<<1;
                    else
                    cout<<0;
                }
                else if(s=='C')
                {
                    if(c=='B')
                    cout<<1;
                    else
                    cout<<0;
                }
                else if(s=='B')
                {
                    if(c=='A'||c=='C')
                    cout<<1;
                    else
                    cout<<0;
                }
                else if(s=='A')
                {
                    if(c=='B')
                    cout<<1;
                    else
                    cout<<0;
                }
            }
            else
            cout<<"00";
        }
    }
    cout<<"\n";
    return 0;
}