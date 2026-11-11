#include<bits/stdc++.h>

using namespace std;

int n;
long long at,result;
char t[200001];
long long c[200001];

int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> c[i] >> t[i];
        at += c[i];
    }
    int ln = 0,rn = 0;
    int l = 0,r = n-1;

    while(l < r){
        if(t[l] != t[r]){
            //result is added
            if(c[l] > c[r]){
                result += c[r];
                c[l] -= c[r];
                r--;
            }else if(c[l] < c[r]){
                result += c[l];
                c[r] -= c[l];
                l++;
            }else{
                result += c[l];
                l++;
                r--;
            }
        }else{
            //just moving
            if(c[l] > c[r]){
                c[l] -= c[r];
                r--;
            }else if(c[l] < c[r]){
                c[r] -= c[l];
                l++;
            }else{
                l++;
                r--;
            }
        }
    }cout << result;
    return 0;
}