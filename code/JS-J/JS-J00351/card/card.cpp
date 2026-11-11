#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn];
int t[maxn];
int cnt[maxn];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int top=0;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int flag=0;
            for(int tg=0;tg<=top;tg++)
            {
                if(t[tg]==a[j])
                {
                    flag=1;break;
                }
            }
            if(flag==1)
            {
                for(int tg=0;tg<=top;tg++)
                {
                    t[tg]=0;
                }
                top=1;
                t[top]=a[j];
            }
            else
            {
                top++;
                t[top]=a[j];
            }
        }
        for(int tg=1;tg<=top;tg++)
        {
            cnt[t[tg]]++;
        }
        top=0;
        for(int tg=0;tg<=top;tg++)
        {
            t[tg]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    return 0;
}
