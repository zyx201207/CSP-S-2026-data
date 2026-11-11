#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt=0;
const int MAXN=2e5+5;
struct lr
{
    int a;
    char c;
}x[MAXN];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i].a>>x[i].c;
    int l=1,r=n;
    while(l<r)
    {
        int cur=min(x[l].a,x[r].a);
        if(x[l].c!=x[r].c) cnt+=cur;
        //cout<<"(l,r)="<<l<<' '<<r<<",cur="<<cur<<",cnt="<<cnt<<endl;
        if(x[l].a<x[r].a)
        {
            l++;
            x[r].a-=x[l-1].a;
        }
        else if(x[l].a>x[r].a)
        {
            r--;
            x[l].a-=x[r+1].a;
        }
        else
        {
            l++;
            r--;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
