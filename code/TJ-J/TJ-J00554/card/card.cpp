#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,a[50005],b[50005],c[50005];
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int x=0;x<n;x++){
    for(int i=0;i<m;i++){
        for(int j=0;j<i;j++){
            for(int k=j+1;k<i;k++){
                c[i]=a[i];
                if(c[i]==c[j]){
                    c[j]=c[i];
                    c[k]=0;
                }
            }
        }
    }
    for(int y=1;y<n;y++){
        if(c[y]==0){
            b[c[0]]++;
        }
    }
}
for(int i=0;i<m;i++){
    cout<<b[i]<<' ';
}

return 0;
}
