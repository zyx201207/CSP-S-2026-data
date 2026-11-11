#include<bits/stdc++.h>
using namespace std;
const int N=200010;
long long a[N],b[N],c[N];
int n,m;
bool cmp(long long a,long long b){
    return a>b;
}
long long cn;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int ib=0,ic=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]%2==1)
        {
            b[ib]=a[i];
            ib++;
        }else
        {
            c[ic]=a[i];
            ic++;
        }
    }
    sort(b,b+ib,cmp);
    sort(c,c+ic,cmp);
    if(ic==0)
    {
        cn=b[0]&b[1];
        for(int i=2;i<m;i++)
        {
            cn=cn&b[i];
        }
    }else if(ib==0)
    {
        cn=c[0]&c[1];
        for(int i=2;i<m;i++)
        {
            cn=cn&c[i];
        }
    }else
    {
        int ci=0,bi=1;
        while(b[0]<c[ci])
        {
            ci++;
        }
        if(ic==ci)
        {
            cn=c[0]&c[1];
            for(int i=2;i<m;i++)
            {
                cn=cn&c[i];
            }
        }else
        {
            cn=b[0]&c[ic];
            for(int i=2;i<m;i++)
            {
                if(cn&b[ib]>cn&c[ic])
                {
                    cn=cn&b[ib];
                    ib++;
                }else
                {
                    cn=cn&c[ic];
                    ic++;
                }
            }
        }

    }
    cout<<cn;
    return 0;
}
