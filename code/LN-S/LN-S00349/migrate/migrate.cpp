#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t;
int n[100000],d[100000];
int l[100000][2000000];
int panding(int a){
    int d = l[a][1] - l[a][0];
    int k = d[a]/d;
    if (k != 0){
        int m = 2*k-1;
        if (n[a]-m+1>0){
            return n[a]-m+1;
        }
    }
    return 0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;
    int n[100000],d[100000];
    int l[100000][2000000];
    for (int k = 0;k < t;k++){
        cin >> n[k] >> d[k];
        for (int i = 0;i < n;i ++){
            cin >> l[k][i];
        }
        cout << panding(k) << endl;
    }
    return 0;
}
