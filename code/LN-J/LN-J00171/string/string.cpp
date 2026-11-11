#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string ss=" ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int aa;
        cin>>aa;
        char ch;
        cin>>ch;
        for(int i=1;i<=aa;i++)
        {
            ss+=ch;
        }
    }
    for(int i=0;i<ss.size();i++)
    {
        char ccc=ss[i];
        if(ccc==' ')
        {
            for(int j=i;j<ss.size();j++)
            {
                ss[j]=ss[j+1];
            }
            ss.size()-=1;
            break;
        }
    }
    long long len,mid;
    len=ss.size();
    mid=len/2;
    int num=0;
    for(int i=0;i<mid;i++)
    {
        char aaa=ss[i];
        char bbb=ss[len-1-i];
        if(aaa!=bbb)
        {
            num++;
        }
    }
    cout<<num;
    return 0;
}
