#include<bits/stdc++.h>

using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int c=0,ax=0;
    for (int i=0;i<n;i++){
        int b[n]={};
        int M=m;
        for (int j=0;j<n;j++){
            if (a[i]>a[j]){
                b[j]=a[i]-a[j];
            }
        }
        c=0;
        for(int z=0;z<n;z++){
                if (M-b[z]>=0 && b[z]!=0){
                        M-=b[z];
                        c+=1;
                }
        }
        for (int g=0;g<n;g++){
            if (a[g]==a[i]){
                c+=1;
            }
        }
        ax=max(c,ax);
    }
    cout<<ax;
    return 0;
}
