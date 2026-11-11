#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[1000005],x,c,num=0,sum=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> c;
        for(int j=0;j<x;j++){
            a[j]==c;
            num++;
        }
    }
    for(int i=0;i<num;i++){
        if(a[i]!=a[num+1-i]){
            sum++;
        }
    }
    cout << sum;
    return 0;
}
