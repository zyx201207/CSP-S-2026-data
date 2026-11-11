#include <bits/stdc++.h>
using namespace std;
const int maxn=500005;
long long a[maxn],m;
int n,num;
bool checkA(){
    for(int i=1;i<n;i++){
        if(a[i]!=a[i+1]){
            return 0;
        }
    }
    return 1;
}
bool checkC(){
    int sum=0;
    for(int i=1;i<n;i++){
        sum+=a[n]-a[i];
    }
    if(sum<=m){
        return 1;
    }
    return 0;
}
bool checkB(){
    for(int i=1;i<n-1;i++){
        if(a[i+1]-a[i]!=a[i+2]-a[i+1]){
            return 0;
        }
    }
    return 1;
}
int solveB(int mm){
    for(int i=1;i<n;i++){
        mm-=i*(a[2]-a[1]);
        if(mm<0){
            return i-1;
        }
    }
    return n;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(checkA() || checkC()){
        cout<<n;
        return 0;
    }
    if(checkB()){
        cout<<solveB(m);
        return 0;
    }
    num=0;
    for(int i=2;i<=n;i++){
        int mm=m,numm=0;
        for(int j=i-1;j>=1;j--){
            if(mm-a[i]+a[j]){
                mm-=(a[i]-a[j]);
                numm++;
            }
            else{
                break;
            }
        }
        num=max(num,numm);
    }
    cout<<num;
    return 0;
};
