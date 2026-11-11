#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int a[N];
int b[N];
int c[N];
void clearst(){
    for(int i=1;i<n;i++){
        a[i]=0;
    }
}

int main(){
    freopen("card.in","w",stdin);
    freopen("card.out","r",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        b[a[i]]++;
        if(b[a[i]]>1){
            clearst();
            b[a[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(b[i]==1) c[i]++;
        }
        clearst();
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }




    return 0;
}
