#include<bits/stdc++.h>
using namespace std;
int n,m,a[500050],len,numi[300030];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int k=1;k<=n;k++){
        int b[500050]={},num[300030]={};
        len=0;
        for(int i=k;i<=n;i++){
            len++;
            b[len]=a[i];

            if(num[b[len]]!=0&&num[b[len]]<=len&&b[num[b[len]]]==b[len]){
                len=num[b[len]];
            }else num[b[len]]=len;
           // cout<<" ";
          //  for(int i=1;i<=len;i++){
           //     cout<<b[i]<<" ";
        //    }
         //   cout<<endl;

        }
        for(int i=1;i<=len;i++){

            numi[b[i]]++;
            //cout<<b[i]<<" ";
        }
     //   cout<<endl;

    }
    for(int i=1;i<=m;i++){
        cout<<numi[i]<<" ";
    }

    return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
3 2
*/
