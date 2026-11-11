#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int arr[500010],stk[500010],cnt[300010];
bool num[300010];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,lst=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }for(int i=n;i>=1;i--){
        stk[++lst]=arr[i];
        if(!num[arr[i]]){
            num[arr[i]]=true;
            cnt[arr[i]]+=i;
        }
        else{
            while(stk[--lst]!=arr[i]){
                num[stk[lst]]=false;
                cnt[stk[lst]]-=i;
            }
        }
    }copy(cnt+1,cnt+m+1,ostream_iterator<int>(cout," "));
    return 0;
}
