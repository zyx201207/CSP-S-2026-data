#include<bits/stdc++.h>
using namespace std;
int a[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int p[n];
    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<n;i++){
        int g[n]={-1},n1=n-i,c=0,s=i,x=-1;
        while(n1>0){
            for(int j=0;j<n;j++){
                if(p[s]==g[j]){
                    x=j+1;
                    break;
                }
            }
            if(x<0){
                g[c]=p[s];
                c++;
                s++;
            }
            else{
                for(int j=n-2;j>=x;j--){
                    g[j]=-1;
                }
                c=x;
                g[c]=p[s];
                c++;
                s++;
            }
            n1--;
        }
        for(int i=0;i<n;i++){
            a[g[i]]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<a[i]<<" ";
    return 0;
}
