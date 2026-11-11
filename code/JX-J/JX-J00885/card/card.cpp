#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,a[500005],m,k[500005]={0},b[300005]={0};
    int maxx=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    for(int i=0;i<n;i++){
        if(maxx<b[a[i]]){
            maxx=b[a[i]];
        }
    }
    for(int h=0;h<n;h++){
        for(int i=h;i<n;i++){
            k[a[i]]++;
            if(b[a[i]]==maxx){
                for(int j=n;j>i;j--){
                    k[a[j]]++;
                    if(b[a[j]]==maxx){
                        break;
                    }
                }
            }

        }
    }
    for(int i=1;i<=m;i++){
        cout<<k[a[i]]<<" ";
    }
    return 0;
}
