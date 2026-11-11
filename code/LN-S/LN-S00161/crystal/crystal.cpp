#include<bits/stdc++.h>
using namespace std;
long long a[500001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i = 0;i<n;i++){
        while(a[i]<a[i+1]){
            for(int j = 0;j<=i;j++){
                a[j]++;
                m--;
                if(m == 0){
                    break;
                }
            }
            if(m == 0){
                for(int j = 0;j<i;j++){
                    a[j] = a[i];
                }
                break;
            }
        }
        if(m == 0){
            break;
        }
    }
    int ans = 1;
    for(int i = 1;i<n;i++){
        if(a[i-1] == a[i]){
            ans++;
        }else{
            break;
        }
    }
    cout<<ans;
    return 0;
}
/*
8 10
4 3 7 6 1 4 2 3*/

