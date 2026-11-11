#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n;
    cin>>n;
    long long m;
    cin>>m;
    if(m==n){
        int num;
        cin>>num;
        for(int i=0;i<n-1;i++){
            int a;
            cin>>a;
            num&=a;
        }
        cout<<num;
        return 0;
    }
    if(m==1){
        int ma=-1;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            ma=max(a,ma);
        }
        cout<<ma;return 0;
    }

    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ma=-1;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            ma=max(ma,a[i]&a[j]);
        }
    }cout<<ma;
    return 0;
}
