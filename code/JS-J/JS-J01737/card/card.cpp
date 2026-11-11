#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==2){
        int s1=n,s2=n;
        if(a[n]!=a[n-1]){
            if(a[n-1]==1)s1--;
            else s2--;
        }
        else{
            if(a[n]==1)s2=0;
            else s1=0;
        }
        cout<<s1<<' '<<s2;
    }
    return 0;
}
