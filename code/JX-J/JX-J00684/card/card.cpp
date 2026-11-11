#include<bits/stdc++.h>
using namespace std;
int a[500005],ans1,ans2;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        bool f1=true,f2=true;
        for(int j=i;j<n;j++){
            if(a[j]==1 && f1) {ans1++;f1=false;}
            if(a[j]==2 && f2) {ans2++;f2=false;}
        }
    }
    cout<<ans1<<" "<<ans2;
}
