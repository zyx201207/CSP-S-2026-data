#include <bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2) cout<<"0000";
    else
    {
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            char ss1=s1[2],ss2=s2[2];
            //cout<<ss1<<" "<<ss2<<'\n';
            if(ss1>ss2) swap(ss1,ss2);
            if((ss2<='C')||(ss1=='F'&&ss2=='D'))
            {
                if(int(ss1)+1==int(ss2)&&ss1!='C') cout<<"1111";
                else cout<<"1110";
            }
            else cout<<"1100";
        }
        else cout<<"1000";
    }
    return 0;
}
/*
g++ travel.cpp -std=c++14 -O2 -o travel
./travel
*/

/*
check:
1. a[][]
2. freopen("travel.in","r",stdin);
3. freopen("travel.out","w",stdout);
4. long long
5. shu ju fan wei
6. //Debug
*/