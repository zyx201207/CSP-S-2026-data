#include<bits/stdc++.h>
using namespace std;
int a[5010],f[5010][5010];
string to2(int x){
    if(x == 0) return "0";
    string s;
    while (x > 1) {
        int p = x % 2;
        x /= 2;
        s = char(p + '0') + s;
    }
    s = "1" + s;
    return s;
}
int to10(string s){
    int a = 0;
    int len = s.size();
    for(int i=0;i<len;i++){
        if(s[i] == '1') a += (1 << len-i-1);
    }
    return a;
}
int yu(int xx,int yy){
    string x = to2(xx),y = to2(yy);
    int len1 = x.size();
    int len2 = y.size();
    while(len1 != len2){
        if(len1 < len2){
            len1 ++;
            x = "0" + x;
        }else{
            len2 ++;
            y = "0" + y;
        }
    }
    string ans = "";
    for(int i=0;i<max(len1,len2);i++){
        if( (x[i] == '1') && (y[i] == '1') ){
            ans = ans + "1";
        } else {
            ans = ans + "0";
        }
    }
    return to10(ans);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(m == 1){
        int maxx = -1;
        for(int i=1;i<=n;i++){
            maxx = max(maxx,a[i]);
        }
        cout << maxx << endl;
        return 0;
    }
    else if(m == n){
        int ans = a[1];
        for(int i=2;i<=n;i++){
            ans = yu(ans,a[i]);
        }
        cout << ans << endl;
        return 0;
    } else if(m == 2){
        int maxx = -1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxx = max(maxx,yu(a[i],a[j]));
            }
        }
        cout << maxx << endl;
    }
    else{
        f[0][0] = 0;
        f[1][0] = 0;
        for(int i=1;i<=n;i++){
            f[i][1] = max(f[i-1][1],a[i]);
        }
        for(int i=2;i<=n;i++){
            for(int j=2;j<=i && j<=m;j++){
                int o = f[i-1][j-1],p = a[i];
                int q = yu(o,p);
                f[i][j] = max(f[i-1][j],q);
            }
        }
        cout << f[n][m] << endl;
    }
    return 0;
}
