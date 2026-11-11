#include<bits/stdc++.h>
using namespace std;
stack<int>a;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int t[n+5]={};
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }

    int nm[n+5]={};
    for(int i=1;i<=n;i++){
            int as=0;
    bool sd[m+5]={};

        for(int j=i;j<=n;j++){
            a.push(t[j]);
            as++;
            bool b=0;
        int qwe=0;
        for(int j=as;j>0;j--){
            if(a.top()==t[j]){
               b=1;
               qwe=t[j];
               break;
            }
        }
        int ad=as;
        if(b){
           while(ad--){
              if(a.top()==qwe){
                 break;
              }
              a.pop();
              as--;
           }
        }
        }



        for(int j=1;j<=as;j++){


            if(sd[j]!=1){
            nm[a.top()]++;
            sd[j]=1;
            }

            a.pop();
        }
        while(!a.empty()){
            a.pop();
        }
    }
    for(int j=1;j<=m;j++){
           cout<<nm[j]<<" ";
        }
    return 0;
}
