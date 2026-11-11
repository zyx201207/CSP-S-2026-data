#include<bits/stdc++.h>
using namespace std;
const int maxn=100001;
struct NODE
{
    long long a,c;
}q[maxn];
bool cmp(const NODE &a,const NODE &b)
{
    return a.a<b.a;
}
bool cmp2(const NODE &a,const NODE &b)
{
    return a.c<b.c;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n,m;
    for(int i=1;i<=n;i++){
        cin>>q[i].a;
    }
    sort(q+1,q+n+1,cmp);
    long long zw;
    if(n%2==0){
        zw=(q[n/2].a+q[n/2+1].a)/2;
    }else{
        zw=q[n/2+1].a;
    }
    for(int i=1;i<=n;i++){
        q[i].c=zw-q[i].a;
    }
    sort(q+1,q+n+1,cmp2);
    int z=0;
    while(q[z].c<0&&z<n)z++;
    int cnt=0;
    for(int i=z;i<=n;i++){
        m-=q[i].c;
        if(m<0){
            cout<<cnt;
            return 0;
        }else{
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}