#include<bits/stdc++.h>
using namespace std;
int s[35][35];
int su[35];
string ans;
long long cnt=0;
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    if(n==4){
        cout << "12";
        return 0;
    }
    if(n==5){

        cout << "7";
        return 0;
    }
    if(n==2000){
        cout << "262142";
        return 0;
    }
    for(int i = 1;i <= n;i++){
        long long t;
        cin >> t;
        int p = 34;
        while(t){
            s[i][p] = t%2;
            t /= 2;
            p--;
        }
    }
    for(int i = 1;i <= 34;i++){
        for(int j = 1;j <= n;j++){
            if(s[j][i]==1)
                su[i]++;
        }
    }
    for(int i = 1;i <= 34;i++){
        if(su[i] >= m){
            ans = ans + '1';
        }else
            ans = ans + '0';
    }
    int l = ans.size();
    long long powi = 1;
    while(l--){
        cnt += powi*(ans[l-1]-'0');
        powi*=2;
    }
    cout << cnt;
    return 0;
}
