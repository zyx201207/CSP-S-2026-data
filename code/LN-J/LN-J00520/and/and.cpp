#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    long long maxn=0;
    cin>>n>>m;
        if(m==1){
            for(int i=0;i<n;i++){
                long long a;
                cin>>a;
                maxn=max(maxn,a);
            }
            cout<<maxn;
        }
        else if(m==n){
            for(int i=0;i<n;i++){
                long long a;
                cin>>a;
                if(i==0) maxn==a;
                else maxn=maxn&a;
            }
            cout<<maxn;
        }
        else if(m==2){
            long long l[n];
        for(int i=0;i<n;i++){
            cin>>l[i];
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                maxn=max(l[i]&l[j],maxn);
            }
        }
            cout<<maxn;
        }
        else{
            int o=1;
            for(int i=0;i<n;i++){
                long long a;
                cin>>a;
                        if(o&&a==0){
                            o--;
                            continue;
                        }
                        maxn=maxn&a;

            }
            cout<<maxn;
        }
    return 0;
}
