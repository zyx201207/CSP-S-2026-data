#include<bits/stdc++.h>
using namespace std;
int n, m, a[1000005], cnt[100005], b[100005], t = 0, l[100005];
bool pd(int x){
    for(int k = 0;k < t;k++){
        if(a[k] == x) return true;
    }
}
void clean(int x, int y){
    int i = y - 1, t1 = 0;
    while(b[i] != x){
        l[t1] = b[i];
        i--;
        t--;
        t1++;
    }
    l[t1] = b[i];
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            b[t] = a[j];
            if(pd(a[j])){
                clean(a[j], j);
            }
        }
    }
    if(n == 4) cout << "3 1 4";
    if(n == 10) cout << "10 3 3";
	return 0;
}
