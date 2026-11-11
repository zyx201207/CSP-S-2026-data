#include<bits/stdc++.h>
using namespace std;
int a[211451], a1[211451], ans3[211451];
int ejz[114514], ejz1[114514];
int ans1[114514];
int index_2 = 0;
void erjin(int shu, int shu1){
    int index_ = 0, index_1 = 0, ans = 0, ans2 = 0, p = 1;
    while(shu > 1){
        ejz[index_] = shu % 2;
        shu /= 2;
        index_++;
    }
    ejz[index_] = 1;

    while(shu1 > 1){
        ejz1[index_1] = shu1 % 2;
        shu1 /= 2;
        index_1++;
    }
    ejz1[index_1] = 1;

    for (int i = max(index_, index_1); i>=0; i--){
        ans1[i] = ejz[i] & ejz1[i];
    }
    for (int i = 0; i<=max(index_, index_1); i++){
        if(ans1[i] == 1){
            if(i == 0){
                ans2++;
            }
            else{
                for(int j=1; j<=i; j++){
                     p*=2;
                }
                ans2 += p;
                p = 1;
            }
        }
        ans3[index_2] = ans2;
        index_2++;
    }
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a1[i] = a[i];
    }
    for(int i=0; i <= n-1; i++){
        for(int j=i+1; j < n; j++){
            erjin(a1[i], a1[j]);
        }
    }
    int maxi = ans3[0];
    for(int i=1; i <= index_2-1; i++){
        if(ans3[i] > maxi){
            maxi = ans3[i];
        }
    }
    cout << maxi;
    return 0;
}

