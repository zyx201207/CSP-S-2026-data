#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    char lie1,lie2,a[4];
    int hang1=0,hang2=0;
    a[0]='0';
    a[1]='0';
    a[2]='0';
    a[3]='0';
    cin>>c1>>s1>>c2>>s2;
    lie1=s1[2];
    lie2=s2[2];
    for(int i=0;i<=1;i++)
    {
        hang1=hang1*10+s1[i]-'0';
        hang2=hang2*10+s2[i]-'0';
    }
    if(c1==c2)
    {
        a[0]='1';
        if(hang1==hang2)
        {
            a[1]='1';
            if(lie1<='C'&&lie2<='C'||lie1>'C'&&lie2>'C')
            {
                a[2]='1';
                int x,y;
                x=lie1-lie2;
                y=lie2-lie1;
                if(x==1||y==1)
                    a[3]='1';
            }
        }
    }
    for(int i=0;i<=3;i++) cout<<a[i];
    return 0;
}
