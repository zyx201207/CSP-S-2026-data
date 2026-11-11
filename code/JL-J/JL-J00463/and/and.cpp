#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,a[10086];
    long long b,maxx=0;
    cin>>m>>n;
    for(int i=0;i<m;i++)cin>>a[i];
    if(n==2){
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            b=(a[i]&a[j]);
            if(b>=maxx)maxx=b;
        }
    }
    }
    else if(n==3){
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            for(int k=j+1;k<m;k++){
                b=(a[i]&a[j]&a[k]);
                if(b>=maxx)maxx=b;
            }
        }
    }
    }
    else if(n==4){
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            for(int k=j+1;k<m;k++){
                for(int l=j+1;l<m;l++){
                b=(a[i]&a[j]&a[k]&a[l]);
                if(b>=maxx)maxx=b;
            }
            }
        }
    }
    }
    cout<<maxx;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
