#include<bits/stdc++.h>
using namespace std;

struct seg
{
    char ch;
    long long from,to;
};
seg input[200010];
int inputSeg()
{
    int num;
    cin>>num;
    for(int i=0;i!=num;i++)
    {
        char ch;
        long long n;
        cin>>n>>ch;
        input[i].ch=ch;
        if(i==0)
        {
            input[0].from=0;
            input[0].to=n;

        }
        else
        {
            input[i].from=input[i-1].to;
            input[i].to=input[i].from+n;
        }
    }
    return num;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int len=inputSeg();
    string str="";
    for(int i=0;i!=len;i++)
    {
        for(int j=input[i].from;j!=input[i].to;j++)
        {
            str+=input[i].ch;
        }
    }
    int ans=0;
    int size=str.size();
    for(int i=0;i!=size/2;i++)
    {
        if(str[i]!=str[size-i-1]) ans++;
    }
    cout<<ans;
    return 0;
}
