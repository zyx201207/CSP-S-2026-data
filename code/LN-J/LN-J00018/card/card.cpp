#include <bits/stdc++.h>
using namespace std;
long long n,m,a[5000005],cnt[5000005];
long long aa[5000005],ccnt[5000005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            aa[j]=a[j];
        }
        for(int j=i;j<=n;j++){
            if(ccnt[aa[j]]!=0){
                for(int k=j-1;k>=i;k--){
                    if(aa[k]==aa[j]){
                        aa[k]=0;break;
                    }
                    ccnt[aa[k]]=0;aa[k]=0;
                }
            }
            else{
                ccnt[aa[j]]++;
            }
        }
        for(int j=1;j<=m;j++){
            cnt[j]+=ccnt[j];
            ccnt[j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
