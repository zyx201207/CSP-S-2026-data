#include<bits/stdc++.h>
using namespace std;
string m,x;
int main(){
    /*ios::sync.stdio;
    cin.tie(0);
    cout.tie(0);*/
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,b=0;
    cin>>n>>m;
    int a[n+10];
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    for(int i=1;i<=n;i++){
        for(int j=n;j>i;j--){
            if((a[i]&&a[j])>=b){
                b=a[i]&&a[j];
            }
        }
    }
    cout<<b;
    return 0;
}
