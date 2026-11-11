#include <iostream>
using namespace std;
int n,m;
string n1,m1;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> n >> n1 >> m >> m1;
    if(n==m)
    {
        cout <<"1";
        if(n1[0]==m1[0]&&n1[1]==m1[1])
        {
            cout <<"1";
            if((n1[2]>='A'&&n1[2]<='C'&&m1[2]>='A'&&m1[2]<='C')||(n1[2]>='D'&&n1[2]<='F'&&m1[2]>='D'&&m1[2]<='F'))
            {
                cout <<"1";
                if(m1[2]=='D'||n1[2]=='D')
                {
                    cout <<"1";
                    return 0;
                }
                else if(int(m1[2]+1)==int(n1[2])||int(n1[2]+1)==int(m1[2]))
                {
                    cout <<"1";
                }
                else{
                    cout <<"0";
                }
            }
            else{
                cout <<"00";
            }
        }
        else{
            cout <<"000";
        }
    }
    else{
        cout <<"0000";
    }
}
