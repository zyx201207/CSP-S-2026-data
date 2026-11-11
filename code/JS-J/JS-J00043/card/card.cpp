#include<bits/stdc++.h>
using namespace std;
int n1,m;
int a[500010];
long long d[500010];
int a1[500010];
int b[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n1>>m;
    for(int i=1;i<=n1;i++){
        cin>>a[i];
    }
    d[a[n1]]+=1;
    for(int q=1;q<n1;q++){
        int n=1;
        for(int j=1;j<=500010;j++){
            b[j]=0;
            a1[j]=0;
        }
        for(int i=q;i<=n1;i++){
        if(a1[a[i]]==0){
            b[n]=a[i];
            a1[a[i]]=n;
            n++;
        }else{
            for(int j=a1[a[i]]+1;j<=n;j++){
                a1[b[j]]=0;
            }
            n=a1[a[i]];
        }
        for(int x=1;x<n;x++){
            d[b[x]]+=1;
            //cout<<b[n]<<' '<<i<<endl;
        }


    }
    }
    for(int i=1;i<=m;i++){
        cout<<d[i]<<' ';
    }
return 0;
}
