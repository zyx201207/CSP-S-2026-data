#include<bits/stdc++.h>
using namespace std;
int n,m,sum,res,ans;
int as[2000005];
queue<int> az;
int ax[2010100];
bool asa;
void asd(int x){
   for(int i=x+1;i<n;i++){

            for(int j=0;j<i;j++){
               if(az.front()==as[i]){
                    res=j;
                    for(int k=0;k<j;k++){
                         az.pop();
                    }
                    asa=true;
                break;
               }
               ax[j]=az.front();
               az.pop();
            }
    if(!asa){
        for(int l=res;l<i;l++){
            az.push(ax[l]);
        }
    }
    if(asa){
        for(int l=0;l<i;l++){
            az.push(ax[l]);
        }
    }

               az.push(as[i]);
   }
while(!az.empty()){
    if(az.front()==x+1){
        cout<<x+1;
    }
    az.pop();
}
    asd(x);
 }
int main (){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>as[i];
    }
    asd(0);
    return 0;
}

