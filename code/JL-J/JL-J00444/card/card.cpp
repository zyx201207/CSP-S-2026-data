#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,r,a[2000000],b[2200000],c[2000000],d[2200000];
void qk(int i,int j){
    for(int x=i;x<=j;x++){
        b[x]=0;
    }
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>r;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        d[i]=b[i]=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(b[j]==b[k]){
                    qk(j,k-1);
                }
            }
        }
       /* for(int l=i;l<=n;l++){

            cout<<b[l]<<" ";
        }
        cout<<endl;**/
        for(int l=i;l<=n;l++){
            c[b[l]]++;
           // cout<<b[l]<<" "<<c[b[l]]<<endl;
        }
       /* for(int p=1;p<=r;p++) cout<<c[p]<<" ";
        cout<<endl;*/
        for(int i=1;i<=n;i++){
        d[i]=b[i]=a[i];
    }
    }


    for(int i=1;i<=r;i++) cout<<c[i]<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
