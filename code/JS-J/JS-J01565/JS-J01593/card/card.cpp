#include<bits/stdc++.h>
using namespace std;
int m,n,now;
int a[100005],b[100005],c[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
            if(b[c[j]]==0){
            c[now]=a[j];
            b[c[j]]=1;
        }
        else {
                for(int s=1;s<=now;s++)
        }
    }
    }
    return 0;
}
