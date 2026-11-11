#include <bits/stdc++.h>
using namespace std;
int yu(int a, int b){

    int s1[100000], s2[100000], s3[100000];
    int c1 = 0,c2 = 0,c3 = 0,sum = 0;
    while (a > 0){
        s1[c1] = a%2;
        c1++;
        a /= 2;
    }
    while (b > 0){
        s2[c2] = b%2;
        c2++;
        b /= 2;
    }
    for(int i = 0; i < abs(c1-c2); i++){
        s3[c3] = 0;
        c3++;
    }
    for(int i = 0; i < min(c1, c2); i++){
        if(c1 > c2){
            if(s1[c1-c2-1+i] == s2[i] && s2[i] == 1){
                s3[c3] = 1;
                c3++;
            } else {
                s3[c3] = 0;
                c3++;
            }
            continue;
        } else {
            if(s2[c1-c2-1+i] == s1[i] && s1[i] == 1){
                s3[c3] = 1;
                c3++;
            } else {
                s3[c3] = 0;
                c3++;
            }
        }
    }
    for (int i = 0; i < c3; i++){
        sum += s3[i] * (2^(c3-i));
    }
    return sum;
}

int n,m,ma = 0,cnt;
int s[10000000];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        ma = (ma,s[i]);
    }
    cout << yu(n,ma);
    return 0;
}
