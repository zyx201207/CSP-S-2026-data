#include<bits/stdc++.h>
using namespace std;
long long num[10000005];
char ch[10000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s="";
    for(int i=1;i<=n;i++)
    {

        int a;
        cin>>a;
        char ch;
        cin>>ch;
        for(int j=0;j<a;j++)
            s+=ch;
    }
    int cnt=0;
    int l=0,r=s.size()-1;
    while(r>l)
    {
        if(s[l]!=s[r])
            cnt++;
        r--;
        l++;
    }
    cout<<cnt;
    return 0;
}
