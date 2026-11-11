#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,cnt[200005],ans=0;
char ch[200005];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>cnt[i]>>ch[i];
    }
    int l=1,r=n;
    while(l<=r){
        if(l==r) break;
        if(ch[l]!=ch[r]){
            ans+=min(cnt[l],cnt[r]);
            //cout<<min(cnt[l],cnt[r])<<endl;
            if(cnt[l]>cnt[r]){
                cnt[l]-=cnt[r];
                cnt[r]=0;
                r--;
            }
            else if(cnt[l]<cnt[r]){
                cnt[r]-=cnt[l];
                cnt[l]=0;
                l++;
            }
            else{
                cnt[r]=0;
                cnt[l]=0;
                l++;
                r--;

            }
        }
        else {
            if(cnt[l]>cnt[r]){
                cnt[l]-=cnt[r];
                cnt[r]=0;
                r--;
            }
            else if(cnt[l]<cnt[r]){
                cnt[r]-=cnt[l];
                cnt[l]=0;
                l++;
            }
            else{
                cnt[r]=0;
                cnt[l]=0;
                l++;
                r--;

            }
        }

    }
    cout<<ans<<endl;
    return 0;
}
