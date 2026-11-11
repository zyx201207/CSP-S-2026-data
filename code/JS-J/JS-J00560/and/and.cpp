#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],max0=-1,max1=-1,max2=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int k=0;k<n;k++){
        cin>>a[k];
        if(a[k]>max0)max0=a[k];
    }
    if(m==1){
        cout<<max0;
        return 0;
    }
    if(m==2){
        for(int i=0;i<n;i++){
            for(int x=0;x<n&&x!=i;x++){
                if(a[x]|a[i]>max1){
                    max1=a[x]|a[i];
                }
            }
        }
        cout<<max1;
        return 0;
    }
    if(m==n){
        int y=a[0];
        for(int i=1;i<n;i++){
            y=y|a[i];
        }
        cout<<y;
        return 0;
    }
    if(m==n-1){
        for(int i=0;i<n;i++){
            int p=0;
            for(int j=0;j<n&&j!=i;j++){
                p=p|a[j];
            }
            if(p>max2)max2=p;
        }
        cout<<max2;
        return 0;
    }
    cout<<max0;
    return 0;
}
