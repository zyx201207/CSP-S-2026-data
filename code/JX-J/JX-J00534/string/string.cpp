#include <bits/stdc++.h>
using namespace std;

int a[100005],s[100005];
long long pref1[100005],pref2[100005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        pref1[i] = pref1[i - 1] + a[i];
        string x;
        cin >> x;
        s[i] = x[0] - 'A';
    }
    for(int i = n;i >= 1;i--){
        pref2[n + 1 - i] = pref2[n - i] + a[i];
    }

    int cnt1 = 1,cnt2 = 1;
    long long answer = 0;
    for(int i = 1;i <= (pref1[n] + 1) / 2;i++){
        if(i > pref1[cnt1]){
            cnt1++;
        }
        if(i > pref2[cnt2]){
            cnt2++;
        }
        if(s[cnt1] != s[n + 1 - cnt2]){
            answer++;
        }
    }
    cout << answer;
    return 0;
}
