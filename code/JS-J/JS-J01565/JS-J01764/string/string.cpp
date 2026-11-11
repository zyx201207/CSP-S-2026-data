#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a[1000010],ans=0,cnt=0;
    string kskbl;
    char c[100010];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=a[i];j++)
        {
            kskbl+=c[i];
            cnt++;
        }
    int mid;
    if(cnt%2==0)
    {
        mid=cnt/2;
        for(int i=1;i<=mid;i++)
        {
            if(kskbl[i]!=kskbl[cnt-i+1])
                ans++;
        }
        cout<<ans;
    }
    else
    {
        mid=cnt/2+1;
        for(int i=1;i<mid;i++)
        {
            if(kskbl[i]!=kskbl[cnt-i+1])
                {
                    ans++;
                }
        }
        cout<<ans;
    }
    return 0;
}
