#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool f1=0,f2=0,f3=0,f4=0;
    if(c1[0]==c2[0]&&c1[1]==c2[1]) 
    {
        f1=1;
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            f2=1;
            int zw1=s1[2]-'A'+1,zw2=s2[2]-'A'+1;
            if(zw1>=1&&zw1<=3&&zw2>=1&&zw2<=3||zw1>=4&&zw1<=5&&zw2>=4&&zw2<=5)
            {
                f3=1;
                if(abs(zw1-zw2)<=1)
                {
                    f4=1;
                }
            }
        }
    }
    cout<<f1<<f2<<f3<<f4;
    //cout<<n<<endl;
    return 0;
}