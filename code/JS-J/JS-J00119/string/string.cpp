#include<bits/stdc++.h>
using namespace std;

string S[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,num=0,cnt=0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int a;
        char c;
        cin >> a >> c;
        S[i]=c;
    }
    for(int i=n-1;i<=0;i--)
    {
        SN[i]==S[num];
        num++;
    }
    for(int i=0;i<n;i++)
    {
        if(SN[i]!=S[i])
        e    cnt++;
    }
    cout << cnt;
    return 0;
}
