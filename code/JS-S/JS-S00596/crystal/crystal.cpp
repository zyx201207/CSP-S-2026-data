#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
long long a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int k=1;
    while(1){
        bool f=false;
        //cout<<k<<"========"<<endl;
        for(int i=1;i<=n-k;++i){
            //cout<<i<<"------"<<endl;
            int c=0;
            for(int j=i,t=1;j<=i+k-1;++j,++t){
                c+=(a[j+1]-a[j])*t;
            }
            //cout<<c<<endl;
            if(c<=m){
                f=true;
                break;
            }
        }
        if(f==false) break;
        ++k;
        if(k==m) break;
    }
    cout<<k;
    return 0;
}
