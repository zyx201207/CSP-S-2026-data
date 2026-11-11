#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],;
int ans=0;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j++){
            int i=1;
            long long b[500005]={};
            b[i]=a[j];
            for(int z=1;z<i;z++){
                if(b[i]==b[z]){
                    b[500005]={};
                    b[1]=a[j];
                }
            }
        }
    }

    return 0;
}
