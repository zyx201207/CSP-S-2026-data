#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.in","w",stdout);
    int n,m,a[1001];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int num=0,b=0,c[101],y=1,z=1;
    for(int i=n;i>=1;i--){
        int sum=0;
        for(int j=1;j<=m;j++){
            if(a[i-z]>a[i+y]){
                if(a[i-z]==a[z]){
                    sum++;
                    z++;
                }
                else{
                    a[i-z]++;
                }
            }
            else{
                if(a[i+y]==a[i]){
                    sum++;
                    y++;
                }
                else{
                    a[i+y]++;
                }
            }
        }
        c[i]=sum;
        z=1;
        y=1;

    }
    for(int i=1;i<=n;i++){
        if(c[i]>c[i-1]){
            b=c[i];
        }
    }
    cout<<b;
}
