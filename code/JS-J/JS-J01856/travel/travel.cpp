#include<iostream>
#define AK return
#define CSP 0;
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    //freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
    //freopen//freopen//freopen//freopen//fuckccf//freopen//freopen//freopen//freopen
    //freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
    char a1,b1,c1,d1,e1,a2,b2,c2,d2,e2;
    cin >> a1 >> b1 >> c1 >> d1 >> e1 >> a2 >> b2 >> c2 >> d2 >> e2;
    if(a1 == a2 && b1 == b2)
    {
        if(c1 == c2 && d1 == d2)
        {
            if(e1 == 'D' || e1 == 'F')
            {
                if(e2 == 'D' || e2 == 'F')
                {
                    cout << "1111";
                }
                else
                {
                    cout << "1100";
                }
            }
            else
            {
                if(e2 == 'D' || e2 == 'F')
                {
                    cout << "1100";
                }
                else if(e1 == 'B' || e2 == 'B')
                {
                    cout << "1111";
                }
                else
                {
                    cout << "1110";
                }
            }
        }
        else
        {
            cout << "1000";
        }
    }
    else
    {
        cout << "0000";
    }
    AK CSP
}//luogu donani
