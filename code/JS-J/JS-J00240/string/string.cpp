#include<bits/stdc++.h>
using namespace std;
const int N=200010;
struct p{
    long long q;
    char c;
}a[N];
char s[2*N];
long long sl;
int n,m;
long long g=1;
long long c=0;
long long gcd(long long a,long long b){
    if(b==0)
    {
        return a;
    }
    return gcd(b,b%a);
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].q>>a[i].c;
        g=gcd(g,a[i].q);
    }
    for(int i=1;i<=n;i++)
    {
        a[i].q/=g;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i].q;j++)
        {
            s[sl]=a[i].c;
            sl++;
        }
    }
    for(int i=0;i<sl/2;i++)
    {
        int j=sl-i-1;
        if(s[i]!=s[j])
        {
            c++;
        }
    }
    cout<<c*g;
    return 0;
}
