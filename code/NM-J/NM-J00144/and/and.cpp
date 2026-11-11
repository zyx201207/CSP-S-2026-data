#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long c[1000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >>n >> m;
    for(int i=0; i<n; i++){
        cin >> c[i];
    }
    int s=0,cnt=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            s=c[i]&c[j];
            if(s>cnt){
                cnt=s;
            }
        }
    }
    cout << cnt;
    return 0;
}
