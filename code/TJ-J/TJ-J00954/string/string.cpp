#include <bits/stdc++.h>
using namespace std;
char c;
string k="";
int n,sum=0,x,ls=0;
int p[100001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> x >> c;
        ls+=x;
        for(int j=1;j<=x;j++)
        {
            k+=c;
        }
    }
    for(int i=0;i<=k.size()/2;i++)
    {
        if(k[i]!=k[ls-1-i])
        {
            sum++;
        }
    }
    cout << sum;
    return 0;
}

