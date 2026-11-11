#include <bits/stdc++.h>
using namespace std;
long long crystal[500009]={};
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n=0,m=0;

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> crystal[i];
    }
    sort(crystal,crystal+n);

    long long bac=0,fron=1,aim=crystal[fron],sum=crystal[fron]-crystal[bac],record=0;bool canadd=true;
    while(fron<n){
        if(sum<=m) {fron++;aim=crystal[fron];sum+=(aim-crystal[fron-1])*(fron-bac);}
        else {sum-=(aim-crystal[bac]);bac++;canadd=false;}
        if(sum<=m and record<fron-bac+1 and fron<n) record=fron-bac+1;
    }
    cout << record;
    return 0;
}
