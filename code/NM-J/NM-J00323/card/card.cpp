#include<bits/stdc++.h>
using namespace std;
long long n,m,p[10000000],s=1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }

    for(int i=1;i<=n;i++){
        if(p[s]==p[i]){
            for(int i=s+1;i<=n;i++){
                p[i]={};
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
