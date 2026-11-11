#include<bits/stdc++.h>
using namespace std;
int a[524288];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, mm;
    cin>>n>>mm;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans[524288];
    for(int i=1;i<=n;i++){
        int m[524288] = {0};
        int cnt = 0;
        for(int j=i;j<=n;j++){
            if(m[a[j]]){
                for(int k=m[a[j]];k<=cnt;k++){
                    m[a[k]] = 0;
                }
                cnt = m[a[j]];
            }
            cnt ++;
            m[a[j]] = cnt;
        }
        for(int i=1;i<=cnt;i++){
            ans[m[i]] ++;
        }
    }
    for(int i=1;i<=mm;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
