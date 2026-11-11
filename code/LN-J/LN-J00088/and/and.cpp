#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[1000000],max=0,mxa=-1;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<m;j++){
            max=a[i] and a[i+1];
            if(max>mxa){
            mxa=max;
            }
        }
    }
    cout<<mxa;

return 0;
}
