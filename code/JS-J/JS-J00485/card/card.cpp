#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[300005],a[500005],c[500005];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int j=1;j<=n;j++){
        for(int i=j;i<=n;i++){
            for(int x=j;x<i;x++){
                if(a[x]==a[j]){
                    for(int d=x;d<j;d++){
                        c[d]=1;
                    }
                }
            }
        }
        for(int i=j;i<=n;i++){
            if(c[i]==1){
                c[i]=0;
            }else{
                arr[a[i]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}
