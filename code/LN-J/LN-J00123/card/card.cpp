#include <bits/stdc++.h>
using namespace std;
int a[500005],b[500005][500005],ans[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[a[i]]+=1;
        b[a[i]][0]=i;
    }
    a[1]=1;

    for(int i=1;i<n-1;i++){
        if(b[a[i]]==1){
            for(int j=i-1;j>=0;i--){
            if(b[a[j]]>1&&b[a[j]][0]>i)ans[a[i]]=i-j;
            break;
            }
        }
    }
    return 0;
}
