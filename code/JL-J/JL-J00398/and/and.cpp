#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200001],b[200001],c[200001];
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        cin>>a[i];
        while(a[i]==0){
            b[i]==a[i]%2;
            a[i]==a[i]/2;
        }
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            while(b[j+i]==0 || b[j]==0){
                int x=0;
                if(b[i+j]==b[j]){
                    c[i]+=pow(2,x);
                }
                b[i+j]/=10;
                b[j]/=10;
                x++;
            }
        }
    }
    int max=c[0];
    for(int i=1;i<=n;i++){
        if(c[i]>max){
            max=c[i];
        }
    }
    cout<<max;
    return 0;
}
