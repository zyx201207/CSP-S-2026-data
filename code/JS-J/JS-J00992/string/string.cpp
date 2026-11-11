#include<bits/stdc++.h>
const double PI = 3.14159;
using namespace std;
long long n,len,ans;
struct Letters{
    char letter;
    long long num;
}letters[200005];
bool comparer(long long n1,long long n2)
{
    char c1=' ',c2=' ';
    long long cnt=0;
    for(long long i=1;i<=n;i++)
    {
        if(n1>cnt&&n1<=cnt+letters[i].num) c1=letters[i].letter;
        if(n2>cnt&&n2<=cnt+letters[i].num) c2=letters[i].letter;
        cnt+=letters[i].num;
    }
    if(c1==c2) return true;
    else return false;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        long long x;
        char c;
        cin>>x;
        cin>>c;
        len+=x;
        letters[i].letter=c;
        letters[i].num=x;
    }
    if(len%2==0)
    {
        for(long long i=1;i<=len/2;i++)
        {
            if(!comparer(i,len-i+1)) ans++;
        }
    }
    else
    {
        for(long long i=1;i<=(len+1)/2-1;i++)
        {
            if(!comparer(i,len-i+1)) ans++;
        }
    }
    cout<<ans;
    return 0;
}
