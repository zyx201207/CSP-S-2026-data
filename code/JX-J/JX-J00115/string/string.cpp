
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int sum;
    char ch;
};
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    ios::sync_with_stdio(0);
    cin.tie();
    cin>>n;
    node * a=new node[n+10];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].sum>>a[i].ch;
    }
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    string str;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<a[i].sum;j++)
        {
            str+=a[i].ch;
        }
    }
    for(int i=0;i<str.size()-1;i++)
    {
        if(str[i]!=str[i+1])
        {
            cout<<1<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}
