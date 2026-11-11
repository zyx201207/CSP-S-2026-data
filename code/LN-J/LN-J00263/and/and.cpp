#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001];
bool cmp(int x,int y)
{
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int sum=1,ans=0;
    for(int i=1;i<=n;i++)
    {if(i==1){
        ans+=a[i]&a[i+1];
    }
        else
        {
            ans&=a[i+1];
        }
        sum++;
        if(sum==m)
        {
            break;
        }
    }
    cout<<ans;
return 0;
}
