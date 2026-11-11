#include<bits/stdc++.h>
using namespace std;
int crystal[800005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long m;
    int n;
    int i;
    int q;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>crystal[i];
    }
    sort(crystal,crystal+n);

    for(i=1;i<n;i++){
        q=crystal[i]-crystal[i-1];

        m=m-i*q;
        if(m<=0){

            break;
        }
    }
    while(crystal[i+1]==crystal[i]){
        i++;
        break;

    }
    cout<<i+1;
    return 0;
}

