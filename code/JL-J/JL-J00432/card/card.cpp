#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int a[N],v[N],sum[N];
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int s=0,ji=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(1){
            a[s]=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=0){
        v[a[i]]++;
        ji++;
        if(v[a[i]]>1){
            for(int j=1;j<=m;j++){
                if(v[j]!=0){
                    v[j]--;
                }
            }
        }
        }
    }
    for(int d=1;d<=m;d++){
        if(v[d]==1)
            sum[d]++;
        v[d]=0;
    }
    s++;
    if(ji==1)
        break;
    else
        ji=0;
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

