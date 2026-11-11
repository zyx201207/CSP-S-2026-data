#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2;
long long int a[N],b[N];
int cnt;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;long long int m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=1;i<=n;i++){
        b[i]=(a[i]-a[i-1])*(i-1)+b[i-1];
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(b[j]-b[i]>m){
                cnt=max(cnt,j-i);
                break;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
