#include<bits/stdc++.h>
using namespace std;
long long a[200005], cnt = 0;
char b[200005];
bool q = 0;
int main(){
    freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
        cnt += a[i];
        scanf(" %c", &b[i]);
        if(b[i] != b[i - 1] && i > 0){
            q = 1;
        }
    }
    if(q == 0){
        cout << 0;
        return 0;
    }
    bool flag = 0;
    for(int i = 0; i < (n + 1)/2; i++){
        if(a[i] != a[n - 1 - i] || b[i] != b[n - 1 - i]){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
       printf("%lld", cnt/2);
       return 0;
    }
    cout << 0;
	return 0;
}
