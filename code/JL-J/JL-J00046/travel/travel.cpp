#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,d,t;
	cin>>c>>s>>d>>t;
	if(c!=d)
    {
        cout<<"0000";
	}
        else
        {
            cout<<"1";
                    if((s[0]==t[0])&&(s[1]==t[1]))
                    {
						cout<<"1";
						if((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(t[2]=='A'||t[2]=='B'||t[2]=='C')&&(s[2]!=t[2]))
            {
                cout<<"1";
                if(s[2]-1==t[2]||s[2]==t[2]-1)
                {
                    cout<<"1";
                }
                else
                {
                        cout<<"0";
                }

            }
            else if((s[2]=='D'||s[2]=='F')&&(t[2]=='D'||t[2]=='F'))
            {
                cout<<"1";
                if(s[2]-2==t[2]||s[2]==t[2]-2)
                {
                    cout<<"1";
                }
                else
                {
                        cout<<"0";
                }
            }
            else
            {
                cout<<"0";
            }
                    }
                        else
                    {
                        cout<<"000";
                    }


        }
        return 0;
}
