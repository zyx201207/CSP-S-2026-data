#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[200005],sum=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            sum=max(sum,a[i]);
        }
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                sum=max(sum,a[i]&a[j]);
            }
        }
    }
    else if(m==3){
        for(int i1=1;i1<=n;i1++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i==j) continue;
                    sum=max(sum,a[i]&a[j]);
                }
            }
        }
    }
    else if(m==n){
        sum=a[1];
        for(int i=1;i<=n;i++){
            sum&=a[i];
        }
    }
    else{
        sort(a+1,a+n+1);
        cout<<a[m];
        return 0;
    }
    cout<<sum;
    return 0;
}
