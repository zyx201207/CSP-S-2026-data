#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int a[100005];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i;i<n;i++){
        a[i] = &a[i];
    }
    int x=-1,o=0;
    int l[m];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i]>x){
                x=a[i];
            }
        }
        l[o]=x;
        o++;

    }
    for(int i=0;i<o;i++){
        cout<<l[i];
    }
    return 0;
}
