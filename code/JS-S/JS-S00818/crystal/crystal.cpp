#include<bits/stdc++.h>
using namespace std;


int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin>>n>>m;
    long long a[n];
    long long duo_shao_ge_shui_jing[n];
    for(long long i=0;i<n;i++){
        cin>>a[i];
        duo_shao_ge_shui_jing[i]=1;
    }
    long long cha_ju[n-1][n];
    for(long long i=0;i<n-1;i++){
        for(long long j=i+1;j<n;j++){
            cha_ju[i][j]=a[j]-a[i];
        }
    }
    for(long long i=0;i<n-1;i++){
        long long zero_one_bag[m];
        long long weights[i],values[i];
        for(long long j=0;j<i;j++){
            weights[j]=cha_ju[j][i];
            values[j]=1;
        }
        for(long long p=0;p<i;p++){
            for(long long j=0;j<m;j++){
                if(j>weights[p]){
                    zero_one_bag[j]=max(zero_one_bag[j],zero_one_bag[j+1-weighs[j]]+values[j]);
                }
            }
        }
        duo_shao_ge_shui_jing[i]+=zero_one_bag[m-1];
    }



    long long the_max=0;
    for(long long i=0;i<n;i++){
        the_max=max(duo_shao_ge_shui_jing[i],the_max);
    }
    cout<<the_max;
    return 0;
}
