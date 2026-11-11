#include<bits/stdc++.h>
using namespace std;
long long arr[500005];
long long ans[300005];
long long pos[300005];
long long ar[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        ar[i]=i+1;
    }
    for(int i=n;i>=1;i--){
        if(!pos[arr[i]]){
            pos[arr[i]]=i;
        }
        else{
            ar[i]=pos[arr[i]]+1;
        }
    }
    for(int i=n;i>=1;i--){
        long long x=arr[i];
        int pos=i;
        while(pos<=n){
            ans[x]++;
            pos=ar[pos];
            x=arr[pos];
        }
    }
    for(int i=1;i<=m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
