#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000"<<endl;
    }
    else
    {
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            int x=s1[2]-'A';
            int y=s2[2]-'A';
            if(x>y)swap(x,y);
            if((x<=2&&y<=2)||(x>=3&&y>=3))
            {
                if(x==y-1&&x!=2)
                {
                    cout<<"1111"<<endl;
                }
                else
                {
                    cout<<"1110"<<endl;
                }
            }
            else
            {
                cout<<"1100"<<endl;
            }
        }
        else
        {
            cout<<"1000"<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
