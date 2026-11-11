#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long tem;
int a[100000000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","r",stdout);
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>a[i];

    }
    int w=0;
    for(int i=n-1;i>0;i--){
        w+=i;
    }
    int maxv=-999999;
    for(int i=0;i<w;i++){
        for(int j=0;j<w;j++){
                if(i!=j){
                int ans=0;
                ans+=(a[i]&&a[j]);
                maxv=max(ans,maxv);
                }

        }


    }
    cout<<maxv;



    return 0;
}
