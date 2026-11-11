#include<bits/stdc++.h>
using namespace std;
const int maxs=5e5+5;
const int maxx=3e5+5;
int book[maxx];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[maxs];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bool t=true;
    for(int i=1;i<=n;i++){
        if(a[i]>a[i+1]){
            t=false;
            break;
        }
    }
    if(t){
        for(int i=1;i<=n;i++){
            if(a[i+1]!=a[i]){
                cout<<i<<" ";
            }
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        int temp[maxs];
        for(int j=i;j<=n;j++){
            temp[j]=a[j];
            for(int k=i;k<j;k++){
                if(temp[k]==temp[j]){
                    for(int l=k;l<j;l++){
                        temp[l]=0;
                    }
                }
            }
        }
        for(int j=i;j<=n;j++){
            book[temp[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<book[i]<<" ";
    }
    return 0;
}
