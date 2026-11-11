#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m;
    string q,p;
    cin>>n>>q>>m>>p;
    if(n==m)
    {
        cout<<"1";
    }
    else cout<<"0";
    //---------------------------------------------
    if(q[0]==p[0]&&q[1]==p[1]&&n==m)
    {
        cout<<"1";
    }
    else cout<<"0";
    //-----------------------------------------------
    if(q[0]==p[0]&&q[1]==p[1]&&n==m)
    {

        if(q[2]=='A'||q[2]=='B'||q[2]=='C'&&p[2]=='A'||p[2]=='B'||p[2]=='C') cout<<"1";
        else if(p[2]=='A'||p[2]=='B'||p[2]=='C'&&q[1]=='A'&&q[2]=='B'||q[2]=='C')
        {
            cout<<"0";
        }
        else if(q[2]=='D'||q[2]=='F'&&p[2]=='D'||p[2]=='F')
        {
            cout<<"1";
            }
        else if(p[2]=='D'||p[2]=='F'&&q[2]=='D'||q[2]=='F')
        {cout<<"1";}
        else cout<<"0";
    }
    else cout<<"0";
    //--------------------------------------------------
    int flag=0;
    if(p[2]=='A'&&q[2]=='B'||q[2]=='A'&&p[2]=='B'&&n==m)
    {
        if(n==m&&q[0]==p[0]&&q[1]==p[1])
        {
            cout<<"1";
            return 0;
        }

    }
    if(p[2]=='B'&&q[2]=='C'||q[2]=='B'&&p[2]=='C'&&n==m)
    {
        if(n==m&&q[0]==p[0]&&q[1]==p[1])
        {
            cout<<"1";
            return 0;
        }
    }
    if(p[2]=='D'&&q[2]=='F'||q[2]=='D'&&p[2]=='F'&&n==m)
    {
         if(n==m&&q[0]==p[0]&&q[1]==p[1])
        {
            cout<<"1";
            return 0;
        }
    }
        cout<<"0";
        fclose(stdin);
        fclose(stdout);
    return 0;
}
