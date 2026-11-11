#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int c1,c2,n,m;
string s1,s2;
char x,y;

bool check(char x,char y)
{
    if(x=='F'||y=='F')
    {
        if(x=='D'||y=='D')
        {
            return true;
        }
        else return false;
    }
    else
    {
        if(x!='D'&&y!='D') return true;
        else return false;
    }
    return false;
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int l1=s1.length();
    int l2=s2.length();
    for(int i=0;i<l1;i++)
    {
        if(s1[i]>='0'&&s1[i]<='9')
        {
            n=n*10+s1[i];
        }
        else x=s1[i];
        if(s2[i]>='0'&&s2[i]<='9')
        {
            m=m*10+s2[i];
        }
        else y=s2[i];
    }
    if(c1==c2)
    {
        cout<<"1";
        if(n==m)
        {
            cout<<"1";
            if(check(x,y))
            {
                cout<<"1";
                if(x-1==y||x+1==y&&x+1!='D') cout<<"1";
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";


    return 0;
}
