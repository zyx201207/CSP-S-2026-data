#include<bits/stdc++.h>
using namespace std;
stack<int> poker;

int a[500010]={};
int jv[300010]={};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
       cin>>a[i];
    }
    for(int i=0;i<n;i++){
            int chang[300010]={};
        for(int j=i;j<n;j++){
            if(chang[a[j]]==1){
                int jj=j-1;
                while(a[jj]!=a[j]){
                    chang[a[jj]]=0;
                    jj--;
                }
            }else{
                chang[a[j]]=1;
            }
        }
        for(int j=1;j<=m;j++){
            jv[j]+=chang[j];

        }
    }
    for(int i=1;i<=m;i++){
        cout<<jv[i]<<' ';
    }
    return 0;
}
