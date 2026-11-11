#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m,cnt=0,mcnt=0;
    cin>>n>>m;
    long long a[n];
    long long sumif=m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=1;i<n;i++){
        sumif=m;
        cnt=0;
        for(int j=i-1;j>=0;j--){
            if(sumif-(a[i]-a[j])>=0){
                sumif=sumif-(a[i]-a[j]);
                cnt++;
            }
            else{
                break;
            }
        }
        mcnt=max(mcnt,cnt);
    }
    cout<<mcnt+1;
    return 0;
}
