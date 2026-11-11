#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n >>m;
    int c=0;
    int d=1;
    cin >>a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        if(a[i]!=a[i-1]){
            d=0;
        }
    }
    if(d){
        cout << n;
        return 0;
    }
    sort(a+1,a+1+n);
    c=a[2]-a[1];
    int y=1;
    while(m>0){
        if(m-c*y>=0){
                m-=c*y;
                y++;
            }
            else{
                break;
            }
    }
    cout << y;
    return 0;
}
