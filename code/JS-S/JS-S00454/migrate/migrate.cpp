#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("midrate.out","w",stdout);
    int c  ,  t ;
    cin >> c >> t ;
    while(t--)
    {
            int n , d;
            cin >> n >> d;
            int s[n+2]={};
            for(int i = 1 ; i <=  n ; i ++)
            {
               cin >> s[i];
            }
            int dd = s[2]-s[1];
            int ddd = d/dd;
            if(ddd==1)
            {

                cout << 0 << endl;
            }
            else
            {
                cout << n - ddd - 1<< endl;
            }
    }
    return 0;
}
