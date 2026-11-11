#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,ans;
int cu1,cu2;
pair<int,char>a[N];
signed main()
{
//#ifndef ZHOUYUDEBUG666
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
//#endif
    std::ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    cu1=1;cu2=n;
    while(cu1<=cu2){
        if(a[cu1].first<a[cu2].first){
            if(a[cu1].second!=a[cu2].second){
                ans+=a[cu1].first;
            }
            a[cu2].first-=a[cu1].first;
            cu1++;
        }
        else if(a[cu1].first>a[cu2].first){
            if(a[cu1].second!=a[cu2].second){
                ans+=a[cu2].first;
            }
            a[cu1].first-=a[cu2].first;
            cu2--;
        }
        else {
            if(a[cu1].second!=a[cu2].second){
                ans+=a[cu2].first;
            }
            cu2--;cu1++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
