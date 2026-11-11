#include<bits/stdc++.h>
using namespace std;
int g,h,l,r,ans=0,n;

char f,a[2000000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h>>f;
        for(int j=1;j<=h;j++){
            a[g]=f;
            g++;
        }
    }

    if(g%2==0){
        l=r=g/2;
    }
    else{
        l=g/2;
        r=g/2+1;
    }
    while(l!=0){
        if(a[l]!=a[r]){
            ans++;

        }

        l--;
        r++;
    }
    cout<<ans;
    return 0;
}
