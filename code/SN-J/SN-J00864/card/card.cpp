#include <iostream>
#include <cstring>
using namespace std;
long long s[300005],n,m,sum[300005],top,a[300005],k[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		memset(k,sizeof(k),0);
		top = 0;
		for (int j = i; j <= n; j++){
			if (k[a[j]] == 0){
				s[++top] = a[j];
				k[a[j]]++;
			}
			else{
				while (s[top] != a[j]){
					k[s[top]] = 0;
					top--;
				}
			}
		}
		for (int j = 1; j <= top; j++){
			sum[s[j]]++;
		}
	}
	for (int i = 1; i <= m; i++){
		cout << sum[i] << " ";
	}
	return 0;
}
