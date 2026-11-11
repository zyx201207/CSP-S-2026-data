#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,l[20005],cnt[20005]={0};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>l[i];
    }
    for(int k=1;k<=n;k++){
        int stat=1,now[20005]={0},tur[20005]={0},lf[20005]={0},rf[20005]={0},lrs=0;
        for(int i=k;i<=n;i++){
            bool f=0;
            for(int j=1;j<=lrs;j++){
                if(tur[l[i]]<=rf[j]&&tur[l[i]]>=lf[j]){
                    f=1;
                }
            }
            if(f==0){
                lrs++;
                lf[lrs]=tur[l[i]];
                rf[lrs]=i-1;
            }
            now[l[i]]=stat;
            tur[l[i]]=i;
            stat++;
        }
        for(int i=1;i<=m;i++){
            if(tur[l[i]]!=0){
                bool f1=0;
                for(int j=1;j<=lrs;j++){
                    if(tur[l[i]]<=rf[j]&&tur[l[i]]>=lf[j]){
                        f1=1;
                    }
                }
                if(f1==0){
                    cnt[i]++;
                }
            }
        }
    }
    cnt[l[n]]++;
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
