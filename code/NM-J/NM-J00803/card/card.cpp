#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio;
    cin.tie(0);
    int n,m,a[1005],d[1000];
    cin>>n>>m;
    for(int i=0;i<=m;i++){
        d[i]=i;
    }
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    for(int i=0;i<n;i++){
        int b[100];
        for(int j=i;j<n;j++){
            b[a[j]]++;
            if(b[a[j]]==2){
                for(int c=0;c<1000;c++){
                    b[c]=0;
                }
            }
        }
        for(int e=1;e<m;e++){
            if(b[e]==1){
                d[e]++;
            }
        }

        
    }
    for(int i=1;i<=m;i++){
        cout<<d[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}