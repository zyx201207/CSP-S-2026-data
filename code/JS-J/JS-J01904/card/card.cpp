#include<bits/stdc++.h>
using namespace std;
int n,m;
int point[500003];
int table[500003];
int cnt[500003];
map<int,int> a;
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>> n >> m ;
    for(int i=1;i<=n;i++){
        cin>> point[i] ;
    }
    for(int j=1;j<=n;j++){
    for(int i=1;i<=n;i++){
        if(i!=1){
            if(point[i-1]==point[i]){
                continue;
            }
        }
        else a[point[i]]++;

    }
    point[j]=-1;
    }
    for(int i=1;i<=n;i++){
        if(i!=1){
            if(point[i-1]==point[i]){
                continue;
            }
        }
        else cout<< a[point[i]] <<" ";
    }
    return 0;
}