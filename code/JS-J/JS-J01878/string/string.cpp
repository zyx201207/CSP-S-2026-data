#include<bits/stdc++.h>
using namespace std;

freopen("string.in","r",stdin);
freopen("string.out","w",stdout);

const int maxn=10e5;
vector<char> str;

int main()
{
    int n; scanf("%d",&n);
    while(n)
    {
        int a; char c;
        cin>>a>>c;
        while(a)
        {
            str.push_back(c);
            a--;
        }
        n--;
    }
    int cnt=0;
    for(int i=0;i<str.size()/2;i++)
    {
        int f=str.size()-1-i;
        if(str[i]!=str[f]) cnt++;
    }
    printf("%d",cnt);
    return 0;
}
