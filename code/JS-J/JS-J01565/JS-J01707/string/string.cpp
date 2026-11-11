#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a;
    int q=0;
    cin>>a;
    string S="";
    for(int i = 1;i<=a;i++)
    {
        int b;
        char c;
        cin>>b>>c;
        for(int i =1;i<=b;i++)
        {
            S+=c;
        }
    }
    int d;
    d=(S.length()+1)/2;
    for(int i = 0;i<=d-1;i++)
    {
        if(S[i]!=S[S.length()-i-1])
        {
            q++;
        }
    }
    cout<<q;
    return 0;
}
