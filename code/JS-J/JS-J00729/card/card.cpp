#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[500005]={0},b[300005]={0},c[300005];
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    int i=0;
    while(i<n){
        c[a[i]]++;
        bool pd[300005]={0};
        pd[a[i]]=1;
        for(int j=n-1;j>i;j--){
            if(b[a[j]]==1&&a[j]!=a[i]&&pd[a[j]]==0){
                c[a[j]]++;
                pd[a[j]]=1;
            }
            if(b[a[j]]>1){
                if(pd[a[j]]==0) c[a[j]]++;
                pd[a[j]]=1;
                break;
            }
        }
        for(int j=i;j<n;j++){
            if(b[a[j]]==1&&a[j]!=a[i]&&pd[a[j]]==0){
                c[a[j]]++;
                pd[a[j]]=1;
            }
            if(b[a[j]]>1){
                if(pd[a[j]]==0) c[a[j]]++;
                break;
            }
        }
        b[a[i]]--;
        i++;
    }
    c[a[n-1]]=n;
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}

