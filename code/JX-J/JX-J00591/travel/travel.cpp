#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a[5][18];
    for(int i = 0;i <= 5;i++){
        for(int j = 0;j <= 18;j++){
            if(i = 1){
                a[i][j] = a[1001][j];
            }
        }
    }
    cout << 1111;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
