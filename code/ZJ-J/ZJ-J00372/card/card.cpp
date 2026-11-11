#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10;

int n,m;
int a[N];
int x[6000+10];
int t[3000+10];
int ans[300010];

void f1(){
	for (int i = 1 ; i <= n ; i++){
		int p = 0;
		memset(t,0,sizeof t);
		for (int j = i ; j <= n ; j++){
			if (t[a[j]] != 0){
				p = t[a[j]];
				memset(t,0,sizeof t);
				for (int k = 1 ; k <= p ; k++){
					t[x[k]] = k;
				}
				x[p] = a[j];
			}
			else{
				x[++p] = a[j];
				t[a[j]] = p;
			}
		}
		for (int j = 1 ; j <= p ; j++)ans[x[j]]++;
	}
	for (int i = 1 ; i <= m ; i++){
		cout << ans[i] << " ";
	}
}

int c[N];
bool vis[N];
void f2(){
	for (int i = 1 ; i <= n ; i++){
		c[a[i]]++;
		if (c[a[i]] == 1)ans[a[i]] += i;
		else ans[a[i]] += 1;
	}
	for (int i = 1 ; i <= m ; i++){
		cout << ans[i] << " ";
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	int f = 1;
	for (int i = 1 ; i <= n ; i++){
		cin >> a[i];
		if (i != 1 && (!(a[i-1] <= a[i])))f = 0;
	}
	if (f){
		f2();
	}
	else{
		f1();
	}
	
	
	return 0;
}
