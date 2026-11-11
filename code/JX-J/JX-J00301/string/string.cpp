/*#include <bits/stdc++.h>
using namespace std;
struct node{
    int sl;
    char c;
}a[200005],l[200005], r[200005];
int sum = 0;
int main(){
	//freopen("string.in", "r", stdin);
	//freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].sl >> a[i].c;
        sum += a[i].sl;
    }
    int lxb = 1, rxb = 1;
    int he = 0;
    int f = 0;
    int xb;
    sum = sum / 2 + bool(sum % 2 == 1);
    for(int i = 1; i <= n; i++){
        he += a[i].sl;
        if(he <= sum){
            l[lxb].sl = a[i].sl;
            l[lxb].c = a[i].c;
            lxb++;
        }
        if(he > sum && f == 0){
            l[lxb].sl = a[i].sl - he + sum;
            l[lxb].c = a[i].c;
            r[rxb].sl = he - sum;
            r[rxb].c = a[i].c;
            xb = i;
            rxb++;
            f = 1;
        }
        if(f == 1 && i != xb){
            r[rxb].sl = a[i].sl;
            r[rxb].c = a[i].c;
            rxb++;
        }
        //cout << he << endl;
    }
    for(int i = 1; i <= lxb; i++) cout << l[i].sl << l[i].c << " ";
    cout << endl;
    for(int i = 1; i <= rxb - 1; i++) cout << r[i].sl << r[i].c << " ";

	return 0;
}*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in", "r", stdin);
	//freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    string s = "";
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int x;
        char c;
        cin >> x;
        cin >> c;
        for(int j = 1; j <= x; j++){
            s += c;
        }
    }
    long long len = s.size();
    for(int i = 0, j = s.size() - 1; i <= len / 2, j >= len - len / 2; i++, j--){
        if(s[i] != s[j]) ans++;
    }
    cout << ans;
    return 0;
}
