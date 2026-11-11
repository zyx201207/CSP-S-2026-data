#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[35],ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=31;j>=0;j--){
            if(((a[i]>>j)&1)==1)
                b[j]++;
        }
    }
    for(int i=31;i>=0;i--){
        if(m<=b[i]){
            ans+=(1<<i);
            for(int j=1;j<=n;j++){
                if(((a[j]>>i)&1)==0){
                    for(int k=i-1;k>=0;k--){
                        if(((a[j]>>k)&1)==1)
                            b[k]--;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
