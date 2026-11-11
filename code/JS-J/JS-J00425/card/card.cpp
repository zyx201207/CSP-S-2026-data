#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],ans[N],cnt[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bool b=1;
    for(int i=2;i<=n;i++){
        if(a[i]<a[i-1]){
            b=0;
        }
    }
    if(b){
        for(int i=1;i<=m;i++){
            cout<<n<<" ";
        }
        return 0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=m;i++){
            cnt[i]=0;
        }
        for(int i=k;i<=n;i++){
            for(int x=1;x<=m;x++){
                if(cnt[x]<0)cnt[x]=0;
            }
            if(cnt[a[i]]==0){
                cnt[a[i]]++;
            }else{
                for(int j=i-1;j>=k;j--){
                    if(a[j]!=a[i]){
                        if(cnt[a[i]]>0)cnt[a[j]]--;
                    }else{
                        cnt[a[i]]--;
                        break;
                    }
                }
                cnt[a[i]]++;
            }
        }
        for(int i=1;i<=m;i++){
            if(cnt[i]==1)ans[i]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
