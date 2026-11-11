#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","r",stdout);
    long long a,b[3][200010],sum = 1,ans = 0;
    queue<long long>d1;
    queue<char>d2;
    queue<long long>e1;
    queue<char>e2;
    cin >> a;
    for (int i = 1;i <= a;i++){
        cin >> b[0][i] >> b[1][i];
        b[2][i] == sum;
        sum += b[0][i];
    }
    for (int i = 1;i <= a;i++){
        if (b[2][i] < sum / 2){
            d1.push(b[0][i]);
            d2.push(b[1][i]);
        }else{
            e1.push(b[0][i]);
            e2.push(b[1][i]);
        }
    }
    while (!d1.empty() && !e1.empty()){
        long long t = min(d1.front(),e1.front());
        if (d2 != e2){
            ans += t;
        }
        d1.front() -= t;
        e1.front() -= t;
        if (d1.front() == 0){
            d1.pop();
            d2.pop();
        }
        if (e1.front() == 0){
            e1.pop();
            e2.pop();
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
