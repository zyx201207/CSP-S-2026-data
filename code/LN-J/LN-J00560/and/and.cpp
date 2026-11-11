#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,max=-1;
    int a[1000];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int c=0;
    for(int i=1;i<=n;i++){
        c=a[i];
        for(int j=i+1;j<=m;j++){
            c=c&a[j];
            m--;
            if(m==0){
                break;
            }
        }
        if(c>max){
            max=c;
        }
    }
    cout<<max;
}
