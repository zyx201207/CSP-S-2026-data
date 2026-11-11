#include<bits/stdc++.h>
using namespace std;

int a[100005]{};
int bucket[2][100005]{};
int cnt[100005]{};

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=0;i<n;++i){

        for(int i=0;i<=1e5+4;++i){
            bucket[0][i]=0;
        }
        for(int i=0;i<=1e5+4;++i){
            bucket[1][i]=1e6;
        }

        for(int j=i+1;j<=n;++j){
            if(bucket[0][a[j]]==0){
                bucket[0][a[j]]=1;
                bucket[1][a[j]]=j;
               //cout<<a[j]<<" ";
            }
            else {
                for(int k=bucket[1][a[j]];k<j;++k){
                    bucket[0][a[k]]=0;

                }
                bucket[0][a[j]]=1;
                bucket[1][a[j]]=j;
            }
        }
        for(int j=1;j<=m;++j){
            if(bucket[0][j]==1){
                cnt[j]++;
            }
        }
    }
    for(int i=1;i<=m;++i)cout<<cnt[i]<<" ";
    return 0;
}
