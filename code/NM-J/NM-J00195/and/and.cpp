#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n;
    int max = 0;
    int a[100010];
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        cin>>a[i];
        if(a[i]>=max){
            max=a[i];
        }
    }
    cout<<a[n-1];
    return 0;
}
