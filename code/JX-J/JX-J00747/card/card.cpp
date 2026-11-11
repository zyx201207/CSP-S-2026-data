#include<bits/stdc++.h>
using namespace std;
int a[500005], v[500005], t[300005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
        cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
        memset(v, 0, sizeof(v));
        int len = 0;
        for(int j = i; j <= n; j++){
            bool f = 0;
            int t = 0;
            for(int k = 1; k <= sizeof(v); k++){
                if(v[k] == a[j]){
                    f == 1;
                    t = k;
                }
            }
            if(f){
                len = t - 1;
            }
            v[++len] = a[j];
        }
        for(int k = 1; k <= sizeof(v); k++){
            t[k]++;
        }
	}
	for(int i = 1; i <= sizeof(t); i++){
        cout << t[i]<<" ";
	}
	return 0;
}
