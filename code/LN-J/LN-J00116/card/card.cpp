#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=200005;
int n,m,cnt=-1,fl=1;
int b[N],c[N];
bool cmp(int x,int y)
{
    return x>y;
}
string x;
int a[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]&&i!=1)
            fl=0;
    }
    if(fl==1)
    {
        for(int i=1;i<=n;i++)
            b[a[i]]++;
        for(int i=1;i<=m;i++)
            b[i]+=b[i-1];
        for(int i=1;i<=m;i++)
            cout<<b[i]<<" ";
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(b[a[j]]>=1){
                for(int k=i;k<j;k++){
                    if(a[k]==a[j])
                    {
                        for(int x=k;x<j;x++)
                            b[a[x]]--;
                    }
                }
            }
            b[a[j]]++;
        }
        for(int i=1;i<=m;i++)
            if(b[i]>0)
                c[i]++,b[i]=0;
    }
    for(int i=1;i<=m;i++)
        cout<<c[i]<<" ";
    return 0;
}
