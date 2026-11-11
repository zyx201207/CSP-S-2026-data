#include<bits/stdc++.h>
using namespace std;
int n;
struct duan
{
    long long l;
    char x;
};
duan a[200005];
int lenth[200005];
int main()
{
    ifstream fin("string.in");
    ofstream fout("string.out");
    fin>>n;
    long long m,len=0,ans=0;
    for(int i=1; i<=n; i++)
    {
        fin>>a[i].l>>a[i].x;
        len+=a[i].l;
        lenth[i]=len;
    }
    long long llen=len;
    if(len%2==1)
    {
        llen--;
    }
    int head=1,tail=n,x=len-1;
    for(long long i=1; i<=(llen/2); i++)
    {
        if(i>lenth[head])
        {
            head++;
        }
        if(x<lenth[tail-1])
        {
            tail--;
        }
        if(a[head].x!=a[tail].x)
        {
            ans++;
        }
        x--;
    }
    fout<<ans;
}
