#include <bits/stdc++.h>
using namespace std;
int aand(int a,int b){
    string dddd = "",eeee = "",ddddn = "",eeeen = "";
    int sumd = 0;
    while (a > 0){
        if (a % 2 == 1){
            dddd += "1";
        }
        else{
            dddd += "0";
        }
        a /= 2;
    }
    while (b > 0){
        if (b % 2 == 1){
            eeee += "1";
        }
        else{
            eeee += "0";
        }
        b /= 2;
    }
    for (int i = dddd.length() - 1;i >= 0;i--){
        ddddn += dddd[i];
    }
    for (int i = eeee.length() - 1;i >= 0;i--){
        eeeen += eeee[i];
    }
    if (ddddn.length() > eeeen.length()){
        int y = ddddn.length() - eeeen.length();
        string h = "";
        for (int i = 1;i <= y;i++){
			h += "0";
		}
        eeeen = h + eeeen;
    }
    else if (ddddn.length() < eeeen.length()){
        int y = eeeen.length() - ddddn.length();
        string h = "";
        for (int i = 1;i <= y;i++){
			h += "0";
		}
        ddddn = h + ddddn;
    }
    string newn = "";
    for (int j = 0;j <= ddddn.length() - 1;j++){
        if (ddddn[j] == '1' && eeeen[j] == '1'){
            newn += "1";
        }
        else{
            newn += "0";
        }
    }
    for (int i = 0;i <= newn.length() - 1;i++){
        sumd += (newn[i] - '0') * pow(2,i);
    }
    return sumd;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.ans","w",stdout);
    int n,m;
    int maxn = -1;
    cin >> n >> m;
    int er[n + 5];
    for (int i = 1;i <= n;i++){
        cin >> er[i];
        if (er[i] > maxn){
            maxn = er[i];
        }
    }
    int maxnn = -1;
    if (m == 1){
        cout << maxn;
    }
    else if (m == 2){
        for (int i = 1;i <= n;i++){
            for (int j = i;j <= n;j++){
                int w = aand(er[i],er[j]);
                if (w > maxnn){
                    maxnn = w;
                }
            }
        }
        cout << maxnn;
    }
    else if (n == 1){
        cout << er[1];
    }
    else if (m == n){
        ffff = aand(er[1],er[2]);
        for (int i = 3;i <= n;i++){
            ffff = aand(ffff,er[i]);
        }
        cout << ffff;
    }

    return 0;
}
