#include<bits/stdc++.h>
using namespace std;
char a[4],b[4],c[4],d[4];
int p[5];
bool gd1,gd2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i = 1;i<=2;i++)cin >> a[i];
    for(int i = 1;i<=3;i++)cin >> b[i];
    for(int i = 1;i<=2;i++)cin >> c[i];
    for(int i = 1;i<=3;i++)cin >> d[i];
    if(b[3] == 'A' ||b[3] == 'B' || b[3] == 'C')gd1 = 1;
    if(d[3] =='A' ||d[3] =='B'||d[3] == 'C')gd2 = 1;
    if(a[1] !=c[1] ||a[2] != c[2])
    {
        p[1]=p[2] =p[3] =p[4] = 0;
    }
    else
    {
        p[1] = 1;
        if(b[1] !=d[1]||b[2]!= d[2])p[2] = p[3] = p[4] = 0;
        else
        {
            p[2] = 1;
            if(gd1!=gd2)p[3] =p[4] = 0;
            else
            {
                p[3] = 1;
                if(gd1 == 1 && (b[3] == 'A'&&d[3] == 'C'||b[3] == 'C'&&d[3] == 'A'))p[4] = 0;
                else p[4] = 1;
            }
        }

    }
    for(int i = 1; i<= 4;i++)cout <<p[i];
    return 0;
}
