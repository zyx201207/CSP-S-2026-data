#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    long long ans = 0;
    string s[200005];
    string str;
    long long len[200005];
    long long tmp;
    long long ggcd;
    long long total_len = 0;
    string ch;
    for(int i=1;i<=n;i++){
        // 求最大公约数
        cin >> tmp;
        if(i == 1){
            ggcd = tmp;
        }
        else{
            ggcd = __gcd(ggcd,tmp);
        }
        len[i] = tmp;
        total_len += tmp;
        cin >> ch;
        s[i] = ch;
    }

    // 压缩字符串
    for(int i=1; i<=n; i++){
        len[i] /= ggcd;
        // cout << i << ' ' << len[i];
    }

    // 统计压缩后的总长度
    for(int i=1; i<=n; i++){
        total_len += len[i];

    }
    // 拼接压缩后的字符串
    for(int i=1; i<=n; i++){
        for(int j=1; j<=len[n]; j++){
            str += s[i];

        }
    }
    str = " " + str;

    // 数字符数量
    for(long long i=1; i*2<=total_len+1; i++){
        if(str[i] != str[total_len+1-i]){
            ans++;
        }
    }

    cout << ans*ggcd;
    return 0;
}
