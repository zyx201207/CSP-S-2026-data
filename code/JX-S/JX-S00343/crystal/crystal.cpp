#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    //cnmd
    long long m,n,x,a[100000];
    cin>>n;
    cin>>m;
    x=1;
    for(long i=1;i<=n;i++){
        cin>>a[i];
    }

    if(a[0]==a[1]){
        cout<<n;
        return 0;
        }
    else if(n==x){
        cout<<x;
        return 0;
    }
    else if(a[1]-a[0]==1){
        cout<<m;
        return 0;
        }
    else if(a[1]-a[0]==2){
        cout<<m/2;
        return 0;
        }
    else if(a[1]-a[0]==3){
        cout<<m/3;
        return 0;
        }
    else if(a[1]-a[0]==4){
        cout<<m/4;
        return 0;
        }
    else{
        cout<<m-1;
        return 0;
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
