#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e6*2+7;
long long a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        int c=0;
        bool f=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i==2){
                c=a[2]-a[1];
            }
            if(i>2&&a[i]-a[i-1]!=c){
                f=1;
                break;
            }
        }
        if(f==1){
            if(c>d){
                cout<<0<<"\n";
            }
            else{
                cout<<(d/c-2)<<"\n";
            }
            return 0;
        }
        cout<<(n-1)<<"\n";
    }
    return 0;
}
