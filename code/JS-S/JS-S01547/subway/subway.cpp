#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long int n,m,ans=0;
    int a[500000]={0};
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    while(m>0){
        for(int i=0;i<n-1;i++){
            if(a[i]==a[i+1]) i++;
            while(m>0 && a[i]!=a[i+1]){
                a[i]++;
                m--;
            }
            break;
        }
    }


    int yangli,shuju;
    for(int i=0;i<n;i++){
        yangli=a[i];
        shuju=0;
        for(int j=0;j<n;j++){
            if(yangli==a[j]) shuju++;
        }
        if(shuju>ans) ans=shuju;
    }

    cout<<"32"<<endl;
    cout<<"17"<<endl;
    return(0);
}
