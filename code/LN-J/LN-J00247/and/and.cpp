#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long x[n],sum=1;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    if(m==n){
        sum=x[0];
        for(int i=0;i<n;i++){
            sum=sum&x[i];
        }
    }
    if(m==1){
        long long maxm=0;
        for(int i=0;i<n;i++){
            if(maxm<x[i]){
                maxm=x[i];
            }
        }
        sum=maxm;
    }
    if(m==2){
        long long maxn=x[0]&x[1];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(x[i]&x[j]>maxn){
                    maxn=x[i]&x[j];
                }
            }
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
