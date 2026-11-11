#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e2+10; 
char idx1r[maxn];
char idx2r[maxn];
char idx1x[maxn];
char idx2x[maxn];
int f1,f2,f3,f4;
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf(" %s %s %s %s",idx1r+1,idx2r+1,idx1x+1,idx2x+1);
    if(!strcmp(idx1r+1,idx1x+1))
    {
        f1=1;
    }
    if(f1)
    {
        int rowr=(idx2r[1]^48)*10+(idx2r[2]^48);
        int rowx=(idx2x[1]^48)*10+(idx2x[2]^48);
        if(rowr==rowx)
        {
            f2=1;
        }
        if(f2)
        {
            int numr=idx2r[3]-'A';
            int numx=idx2x[3]-'A';
            bool fr=numr<=2;
            bool fx=numx<=2;
            if(!(fr^fx))
            {
                f3=1;
            }
            if(f3)
            {
                if(abs(numr-numx)<=1)
                {
                    f4=1;
                }
            }
        }
    }
    printf("%lld%lld%lld%lld",f1,f2,f3,f4);
    return 0;
}
