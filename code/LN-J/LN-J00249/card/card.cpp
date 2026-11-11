#include<bits/stdc++.h>

using namespace std;
const int N=5e5+10;
int a[N];
int ta[N];
int ans[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        int t=1;
        for(int j=i;j<=n;j++){
            for(int k=1;k<t;k++){
                if(ta[k]==a[j]){
                    while(t>k){
                        t--;
                    }
                    break;
                }
            }
            ta[t++]=a[j];
        }
        while(t>1){
            ans[ta[--t]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

