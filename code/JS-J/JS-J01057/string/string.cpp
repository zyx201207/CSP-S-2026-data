#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e5+10;
int n,sum,ans;
int a[N],b[N];
char c[N];

signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i],sum+=a[i],b[i]=b[i-1]+a[i];
    int pos1=1,pos2=sum,id1=1,id2=n;
    while(pos1<pos2&&pos1<=sum&&pos2>=1&&id1<=n&&id2>=1)
    {
        int f=0;
        if(c[id1]!=c[id2])
        {
            if(b[id1]-pos1+1<pos2-b[id2-1]) pos2-=b[id1]-pos1+1,ans+=b[id1]-pos1+1,pos1=b[id1]+1,id1++;
            else if(b[id1]-pos1+1==pos2-b[id2-1]) ans+=b[id1]-pos1+1,pos2=b[id2-1],pos1=b[id1]+1,id1++,id2--;
            else pos1+=pos2-b[id2-1],ans+=pos2-b[id2-1],pos2=b[id2-1],id2--;
        }
        else
        {
            if(id1!=id2)
            {
                if(b[id1]-pos1+1<pos2-b[id2-1]) pos2-=b[id1]-pos1+1,pos1=b[id1]+1,id1++,f=1;
                else if(b[id1]-pos1+1==pos2-b[id2-1]) pos2=b[id2-1],pos1=b[id1]+1,id1++,id2--,f=2;
                else pos1+=pos2-b[id2-1],pos2=b[id2-1],id2--,f=3;
            }
            else break;
        }
    }
    cout<<ans;
    return 0;
}
