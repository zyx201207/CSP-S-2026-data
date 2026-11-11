#include<bits/stdc++.h>
using namespace std;
int a[10000],p[1000];
int main(){
    freopen("area.in","r",stdin);
    freopen("area.out","w",stdout);
    long long n,m,s=0,a;
    cin>>n>>m;
    a=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(1){
        s++;
        for(int i=s;i<=n;i++){
                p[i]=a[i];
            for(int j=s;j<=i;j++){
                if(a[i]==a[j])
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
