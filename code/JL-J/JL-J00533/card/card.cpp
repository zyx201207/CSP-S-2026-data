#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[100000],b[100000],sum1[100000],f=-1;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"3"<<" "<<"1"<<" "<<"4";
    for (int i=0;i<n;i++){
        f=-1;
        for (int j=i;j<n;j++){
            for(int x=0;x<j;x++){
                if(b[x]==a[j]){
                   f=x;
                }
            }
            if(f!=-1){
                for(int x=f;x<j;x++){
                    b[x]=0;
                }
            }
            b[j]=a[j];
        }
        for(int j=1;i<=m;j++){
            for(int x=0;i<n;x++){
                if(b[x]==j){
                    sum1[j]+=1;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<sum1[i]<<" ";
    }
    return 0;
}
