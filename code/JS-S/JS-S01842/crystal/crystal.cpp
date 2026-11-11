#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],Hatsune_Miku=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long r=1,cnt=0;
    for(int l=1;l<=n;l++)
    {
        while(r<n)
        { 
            if(cnt+(a[r+1]-a[r])*(r-l+1)<=m)
            {
                cnt+=(a[r+1]-a[r])*(r-l+1);r++;
            }
            else{
                break;
            }
        }
        Hatsune_Miku=max(Hatsune_Miku,r-l+1);
        cnt-=(a[r]-a[l]);
    }
    cout<<Hatsune_Miku;
}
//开始进食
//考场开暖气，巧克力化了阿啊啊啊啊啊啊啊啊啊啊啊啊！！！！！
/*    ^     ^
    (    v    )
     \Hatsune/
      \Miku /
       \   /
        \ /
         v
💙💙💙💙💙💙💙💙💙
*/