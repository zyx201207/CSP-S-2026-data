#include <bits/stdc++.h>
using namespace std;

long long a[100005],s[100005],the_m[100005][2];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,cnt = 0;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        int num = a[i],seat;
        while(num > 0){
            seat = num % 2;
            if(seat == 1){
                s[i]++;
            }
            num /= 2;
        }
        for(int j = 1;j <= m;j++){
            if(cnt >= m && the_m[j][0] == 0){
                break;
            }
            if(s[j] > the_m[j][0]){
                the_m[j][0] = s[j];
                the_m[j][1] = a[j];
                cnt++;
            }
        }
    }
    int and1 = the_m[1][1];
    //cout << the_m[1][1] << ' ' << the_m[1][0] << endl;
    for(int i = 2;i <= m;i++){
        and1 &= the_m[i][1];
        //cout << the_m[i][1] << ' ' << the_m[i][0] << endl;
    }
    cout << and1;
    return 0;
}
