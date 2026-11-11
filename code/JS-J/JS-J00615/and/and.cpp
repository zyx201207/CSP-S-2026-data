#include<bits/stdc++.h>
using namespace std;
int n,shu[200005],m,s;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>shu[i];
    }
    sort(shu+1,shu+n+1);
    if(m==1){
        cout<<shu[1];
        return 0;
    }
    if(m==n){
        for(int i=1;i<=n;i++){
            s=s&shu[i];
        }
        cout<<s;
    }
    return 0;
}
