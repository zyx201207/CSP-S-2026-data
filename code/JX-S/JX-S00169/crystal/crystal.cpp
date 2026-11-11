#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    int n,m,x=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]>a[j]){
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=2;i<=n;i++){
            int q=1,p=m;
        for(int j=i-1;j>=1;j--){
            if(a[i]-a[j]<=p){
                q++;
                p-=a[i]-a[j];
            }
            else{
                break;
            }
        }
        if(q>x){
            x=q;
        }
    }
    cout<<x;
    return 0;
}
