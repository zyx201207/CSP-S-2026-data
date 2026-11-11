#include<bits/stdc++.h>
using namespace std;
int a[500005],n,m,t1[300005],t2[300005];
stack <int>b;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            t2[a[j]]++;
            if(t2[a[j]]>1){
                while(1){
                    int s=b.top();
                    if(s==a[j]){
                        b.pop();
                        break;
                        t2[s]--;
                    }else{
                        b.pop();
                        t2[s]--;

                    }
                }b.push(a[j]);
            }else{b.push(a[j]);}
        }for(int j=1;j<=m;j++){
            if(t2[j]!=0){
                t1[j]++;
            }t2[j]=0;
        }while(!b.empty()){
            b.pop();
        }
    }for(int i=1;i<=m;i++){
        cout<<t1[i]<<' ';
    }
    return 0;
}
