#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001]={},t[500001]={};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int bjz,bjy;
    for(int i=1;i<=n;i++){
        bjz=i-1,bjy=i-1;
        for(int j=i;j<=n;j++){
            for(int k=i;k<j;k++){
                if(a[j]==a[k]){
                    bjz=k;
                    bjy=j-1;
                    break;
                }
            }
        }
        for(int j=i;j<=n;j++){
            if(j>=bjz && j<=bjy){
                    continue;
            }
            t[a[j]]++;
            //<<t[a[j]]<<" ";
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
//tainanle QWQ
