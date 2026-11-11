#include <bits/stdc++.h>
using namespace std;
int n,m,a[500000]={0},js=1,b=1;
int main(){
    freopen ("crystal.in","r",stdin);
    freopen ("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1; i<=n; i++){
        cin>>a[i];
    }
    for (int i=2; i<=n; i++){
        if (a[b]==a[i]){
            js+=1;
        }
    }
    if(m<=0){
        cout<<js;
    }
    for (int i=1; i<=n; i++){
        if (a[b]==a[i]){
            a[i]+=1;
            a[b]+=1;
            m-=1;
        }
        else{
            b+=1;
            m-=1;
        }
        if (m<=0){
            break;
        }
    }
    js==0;
    for (int i=2; i<=n; i++){
        if (a[b]==a[i]){
            js+=1;
        }
    }
    cout<<js;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
