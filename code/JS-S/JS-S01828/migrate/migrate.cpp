#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+2;
int n,d;
int a[N];
int ans=0x3f3f3f3f,cnt;
void dfs(int pos,int des,int sum)
{
    if(pos==des)
    {
        if(ans>sum)
            ans=sum;
        else if(ans==sum)
            cnt++;
        return ;
    }
    for(int i=pos+1; i<=des; i++)
        if(a[i]-a[pos]<=d)
            dfs(i,des,sum+1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1; i<=n; i++)
            cin>>a[i];
        if(n<4)
        {
            cout<<"0"<<endl;
            continue;
        }
        int otp=0;
        for(int i=1; i<=n; i++)
            for(int j=i+3; j<=n; j++)
            {
                dfs(i,j,0);
                if(cnt==1)
                    otp++;
                cnt=0;
                ans=0x3f3f3f3f;
            }
        cout<<otp<<endl;
    }
    return 0;
}
