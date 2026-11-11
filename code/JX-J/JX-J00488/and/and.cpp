#include<bits/stdc++.h>
using namespace std;

int ej(int x){
    int sum=0;
    while(x!=0){
        sum+=(sum+x%2)*10;
        x/=2;
    }
    return sum;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[1000000000];
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i]=ej(a[i]);
    }
    int f=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=m;j++){
            if(and(a[i],a[j])>f){
                f=and(a[i],a[j]);
            }
        }
    }
    while(f!=0)
    return 0;
}
