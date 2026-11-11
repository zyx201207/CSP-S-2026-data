#include <bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[300001],c[300001],d[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
        cin >> a[i];
	}
	int t[500001],p = 1;
	for (int i = 1;i <= n;i++){
        memset(t,0,sizeof(t));
        memset(b,0,sizeof(b));
        for (int j = i;j<= n;j++){
            int q = a[j];
            if (b[a[j]] == 0){
                t[p] = a[j];
                p++;
                b[a[j]]++;
                c[a[j]] = j;
            }else{
                for (int k = c[a[j]+1];k<=p;k++){
                    b[t[k]] = 0;
                    t[k] = 0;
                }
                p = c[a[j]+1];
            }
        }
        for (int j = 1;j <= p;j++){
            d[t[j]]++;
        }
	}
	for (int i = 1;i <= m;i++){
        cout << d[i] << ' ';
	}
	return 0;
}
