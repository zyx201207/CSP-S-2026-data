#include<bits/stdc++.h>
using namespace std;
string s;
const int N=2e5+5;
int n,cnt[N];
long long ans,cnt1sum,cnt2sum,cntsum;
char a[N];
int main()
{
    freopen("string1.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>cnt[i];
        cin>>a[i];
        cntsum=cntsum+cnt[i];
    }
    int zuo=1,you=n;
    for(long long i=1;i<=cntsum/2;i++)
    {
        if(a[zuo]!=a[you]){
                if(cnt1sum+cnt[zuo]>cnt2sum+cnt[you])
                {
                cnt2sum+=cnt[you];
                ans+=min(cnt[zuo],cnt[you]);
                i+=min(cnt[zuo],cnt[you]);
                you--;
                }
                else if(cnt1sum+cnt[zuo]<cnt2sum+cnt[you])
                {
                cnt1sum+=cnt[you];
                ans+=min(cnt[zuo],cnt[you]);
                i+=min(cnt[zuo],cnt[you]);
                zuo++;
                }
                else{
                    i+=cnt[zuo];
                    ans+=cnt[zuo];
                    zuo++;
                    you--;
                }
        }
        else{
            if(cnt1sum+cnt[zuo]>cnt2sum+cnt[you])
            {
                cnt2sum+=cnt[you];
                you--;
                i+=min(cnt[zuo],cnt[you]);
            }
            else if(cnt1sum+cnt[zuo]<cnt2sum+cnt[you])
                {
                cnt1sum+=cnt[you];
                i+=min(cnt[zuo],cnt[you]);
                zuo++;
                }
            else{
                i+=cnt[zuo];
                    zuo++;
                    you--;
            }
        }
    }
    cout<<ans;
    return 0;
    //cout<<s;
}
