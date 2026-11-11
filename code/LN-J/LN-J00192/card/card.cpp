#include<bits/stdc++.h>
using namespace std;
int n[100005];
int m[10005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int a,b;cin>>a>>b;
    for (int i=1;i<=a;i++){
        cin>>n[i];
    }int sum=0;
    int s=0;
    for (int i=1;i<=a;i++){
        for (int j=1+i-1;j<=a;j++){
            sum+=n[i]%2;
            s+=n[i]%2;
        }
    }cout<<sum<<" "<<s;
    return 0;
}

