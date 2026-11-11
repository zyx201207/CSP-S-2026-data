#include<bits/stdc++.h>

using namespace std;

int n;
long long m;
long long a[500001];
long long mid;
long long ri = LONG_LONG_MIN,le = LONG_LONG_MAX;


int check(int in){
    int r = 0;
    for(int i = 0 ; i < n ; i++){
        if(a[i] < in){
            r += abs(in-a[i]);
        }if(r>m){
            return false;
        }
    }return true;
}

int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        ri = max(ri,a[i]);
        le = min(le,a[i]);
    }
    int next = 0;
    while(le<ri-1){
        mid = (le+ri)/2;
        if(check(mid)){
            le = mid;
        }else{
            ri = mid;
        }
    }if(check(ri)){
        mid = ri;
    }else{
        mid = le;
    }
    int r = 0;
    int used;
    for(int i = 0 ; i < n ; i++){
        if(a[i] <= mid){
            r++;
            used += abs(mid-a[i]);
        }
    }cout << r;
    return 0;
}