#include<bits/stdc++.h>
using namespace std;
int n[100005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b;cin>>a>>b;
    for (int i=1;i<=a;i++){
        cin>>n[i];

    }int sum=0;
    if (b==1){
        for(int i=1;i<=a;i++){
            sum=max(sum,n[i]);
        }
    }cout<<sum;
    return 0;
}
