#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,x;
    cin>>n>>m;
    int a[300005]={};
    bool flag[300005]={};
    for(int i=0;i<n;i++){
        cin>>x;
        if(a[x]==0){
            for(int j=0;j<n;j++){
                if(a[j]!=0&&flag[j])
                    a[j]++;
            }
            a[x]++;flag[x]=true;
        }
        else{
            a[x]++;
            for(int j=0;j<n;j++){
                if(a[j]!=0)
                flag[j]=false;
            }
        }

    }
    for(int i=1;i<=n;i++){
        if(i!=m)
            cout<<a[i]<<' ';
        else
            cout<<a[i];
    }
    return 0;
}
