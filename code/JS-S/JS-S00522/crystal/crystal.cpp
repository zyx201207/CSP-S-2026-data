#include<iostream>
#include<algorithm>
using namespace std;
long long n,k,a[500001],s[500001],ans,cnt,res,lst;
unsigned long long x[500001];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i-1]=a[i]-a[i-1];
    for(int i=1;i<=n;i++) x[i]=x[i-1]+s[i];
    for(int i=1;i<n;i++)
    {
        res+=s[i]*(i-lst);
        cnt++;
        if(res>k)
        {
            for(int j=0;j<i;j++)
            {
                res-=(x[i]-x[j+lst]);cnt--;
                if(res<k) {lst=i-cnt+1;break;}
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans+1;
    return 0;
}
//by undercraft id=914813
//all is well that..................
//x x xxx
//dual:????
//wc,yao pai xu
