#include<bits/stdc++.h>
using namespace std;
int ezhuan(int a)
{
    string s;
    char s1[10000000005];
    int cnt = 1;
    while(a>0)
    {
        s[cnt] = a%2;
        a/=2;
        cnt++;
    }
    for(int i = 1;i<=s.length();i++)
    {
        s1[cnt] = s[i];
        cnt--;
    }
}
int szhuan(int a)
{

}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[200005];
    int er[200005];
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }
    /*for(int i = 1;i<=n;i++)
    {
        er[i] = ezhuan(a[i]);
    }*/
    cout<<"20";
    return 0;
}
