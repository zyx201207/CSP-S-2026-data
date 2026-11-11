#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin >> n;
    long long cr[n];
    cin >> m;
    for (long long i=0;i<n;i++){
        cin >> cr[i];
    }
    long long flag_num=0;
    long long ans=0;
    for (long long i=0;i<n;i++){
        flag_num=cr[i];
        long long temp[n-1];
        for (long long k=0;k<n-1;k++){
            temp[k]=flag_num-cr[k];
            if (temp[k]<0){
                temp[k]=99999999999;
            }
        }
        sort(temp,temp+n-1);
        long long act=m;
        for (long long k=0;k<n-1;k++){
            if(act<temp[k]){
                break;
            }
            act=act-temp[k];
            if (ans<k+1){
                ans=k+1;
            }
        }
    }
    cout << ans << endl;
}
