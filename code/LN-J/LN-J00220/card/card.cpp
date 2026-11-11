#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],ans[200005],b[200005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
            int cnt=0;
        for(int j=1;j<=n;j++){
            for(int p=1;p<=cnt;p++){
                cnt--;
                for(int k=p;k<=j;k++){
                    b[k]=0;
                    cnt--;
                }
            }
        }
        a[j]=b[cnt-1];
    }
    for(int i=1;i<=m;i++){
        ans[b];
        cnt++;
    }
    cout<<ans;
    return 0;
}
