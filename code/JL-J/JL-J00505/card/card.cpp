#include<bits/stdc++.h>
using namespace std;
int a[10005],s[10005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int c[10005]={0},b[10005]={0};
        for(int j=i;j<n;j++){
            b[j]=a[j];
            c[a[j]]++;
            int k=j-1;
            if(c[a[j]]>=2){
                c[a[j]]--;
                while(b[k]!=a[j]){
                    b[k]=0;
                    k--;
                }
                if(b[k]==a[j]){
                    b[k]=0;
                }
            }
        }
        for(int j=i;j<n;j++){
                s[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<s[i]<<" ";
    }
    return 0;
}
