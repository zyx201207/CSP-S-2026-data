#include <bits/stdc++.h>
using namespace std;
int a[100];
char ch[100];
int n;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cin>>ch[i];
    }
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    if(n==2&&ch[0]==ch[1])
    {
        cout<<0;
    }
    else{
        if(a[0]>a[1]) cout<<a[1];
        else cout<<a[0];
        return 0;
    }
    if(n==3&&ch[0]==ch[1]&&ch[1]==ch[2]) {
        cout<<0;
        return 0;
    }
    else
    {
        if(ch[0]==ch[1]&&a[0]+a[1]>a[2]) cout<<a[2];
        else if(ch[0]==ch[1]) cout<<a[0]+a[1];
        if(ch[1]==ch[2]&&a[1]+a[2]>a[2]) cout<<a[0];
        else if(ch[1]==ch[2]) cout<<a[1]+a[2];
        if(ch[0]==ch[2]&&a[0]+a[2]>a[1]) cout<<a[1]-1;
        else if(ch[0]==ch[2]) cout<<ch[0]+ch[2];

        return 0;
    }
}
