#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500000],b[300000],c[300000];
int dg(int e){
    if(e>n-1){
        return 0;
    }
    if(a[e]==a[n-1]){
        b[a[e]]++;
        return 0;
    }
    int x=a[e];
    b[x]++;
    c[x]--;
    if(c[x]==0){
        dg(e+1);
    }
    else{
        for(int i=n-1;i>0;i--){
            if(a[i]==x){
                dg(i+1);
            }
        }
    }

}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]--;
        c[a[i]]++;
    }
    while(1){
        if(c[a[n-1]]==1){
            b[a[n-1]]+=n;
            c[a[n-1]]--;
            n--;
        }
        else break;
    }
    for(int i=0;i<n;i++){
        if(a[i]==a[n-1]){
            b[a[i]]++;
            c[a[i]]--;
            continue;
        }
        dg(i);
    }
    for(int i=0;i<m;i++){
        cout<<b[i]<<' ';
    }
    return 0;
}
