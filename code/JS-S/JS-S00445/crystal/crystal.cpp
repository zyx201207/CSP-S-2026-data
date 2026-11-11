#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500002],spa[500002],spb[500002];
bool isSpecialA=true,isSpecialB=true;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]!=i){
            isSpecialA=false;
        }
        if(isSpecialA||((i>1&&i<n)&&(a[i]-a[i-1]!=a[i+1]-a[i]))){
            isSpecialB=false;
        }
    }
    sort(a+1,a+n+1);
    if(isSpecialA){
        for(int i=1;i<=n;i++){
            spa[i]=(a[i]-a[1])*(a[i]-a[1]+1)/2;
        }
        for(int i=n;i>=1;i--){
            if(spa[i]<=m){
                cout << i;
                return 0;
            }
        }
    }else if(isSpecialB){
        for(int i=1;i<=n;i++){
            spb[i]=(a[i]-a[1])*(a[i]+a[2]-2*a[1])/4;
        }
        for(int i=n;i>=1;i--){
            if(spb[i]<=m){
                cout << i;
                return 0;
            }
        }
    }else{
        for(int i=n;i>=1;i--){
            long long tmp=0;
            bool f=true;
            for(int j=1;j<i;j++){
                tmp+=a[i]-a[j];
                if(tmp>m){
                    f=false;
                    break;
                }
            }
            if(f&&tmp<=m){
                cout << i;
                return 0;
            }
        }
    }
    return 0;
}
