#include<bits/stdc++.h>
using namespace::std;
int n,m;
long long ans[200005],c[200005],a[200005];
int cmp1(int x)
{
    int i=x-1;
    while(a[i] == x)    c[a[i]] = 0;
    return 0;
}
void cmp2()
{
    int i=1;
    while(i <=n)    c[i]=0;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=1,r=1;
    while(l <=n){
        c[a[r]]++;
        if(c[a[r]]==2){
            cmp1(c[a[r]]);
            c[a[r]]--;
        }
        r++;
        if(r == n){
            cmp2();
            for(int i=l;i <=n;i++)  ans[i] +=c[i];
            l++;
        }
    }
    for(int i=1;i <=n;i++)  cout <<ans[i]<<" ";
    return 0;
}
