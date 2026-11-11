#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int main()
{
    freopen("travel.in","r",stdin); 
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string c1,s1,c2,s2;
    std::cin>>c1>>s1>>c2>>s2;
    if (c1!=c2)
    {
        std::cout<<"0000";
        return 0;
    }
    else if (c1==c2)
    {
        std::cout<<1;
        string a1=s1.substr(0,2);
        string a2=s2.substr(0,2);
//        cout<<a1<<" "<<a2<<endl;
        if (a1==a2)
        {
            std::cout<<1;
            char b1=(char)s1[2];
            char b2=(char)s2[2];
//            cout<<b1<<" "<<b2<<endl;
            if ((b1<='C' && b2<='C') || (b1>='D' && b2>='D'))
            {
                std::cout<<1;
                if (abs((int)(b1-b2))==1)
                {
                    std::cout<<1;
                }
                else
                {
                    std::cout<<0;
                    return 0;
                }
            }
            else
            {
                std::cout<<"00";
                return 0;
            }
        }
        else
        {
            std::cout<<"000";
            return 0;
        }
    }
    return 0;
}
//Luogu UID 1814309 求关喵
//9:06 AC T1 被Code Blocks耗了半天, 换成DEV-C++ 
