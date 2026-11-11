//68fen
#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> S;
int cnt=0,len=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int a;
    string c;
    while(n--)
    {
        cin>>a>>c;
        len+=a;
        for(int i=1;i<=a;i++)
             S.push_back(c);
    }
    for(int i=0;i<=len/2;i++)
    {
        if(S[i]==S[len-i])
            continue;
        else
            cnt++;
    }
    cout<<cnt;
    return 0;
}
