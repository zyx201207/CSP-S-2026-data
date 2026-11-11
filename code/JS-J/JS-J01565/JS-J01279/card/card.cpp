#include <bits/stdc++.h>
using namespace std;
int a[600000],b[600000],cnt[400000],p = 1;
int main(){
    int n,m;
    cin>>n>>m;
    for(int  i = 1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    while(m--){
        p++;
        for(int  i = p;i<=n;i++){
            for(int  j = i-1;j>=1;j--){
                if(a[i]==a[j]){
                    for(int k = j;k<i;k++){
                        a[k] = -1;
                    }
                }
            }
        }
        for(int i = p-1;i<=n;i++){
            if(a[i]!=-1){
                cnt[a[i]]++;
            }
        }
        for(int i = 1;i<=n;i++){
            a[i]=b[i];
        }
        n--;
    }
    for(int i = 1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }

    return 0;
}
