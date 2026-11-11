#include<bits/stdc++.h>
using namespace std;
long long m,sum;
int n,I,J,maxx;
int a[200005],b[200005];
int main(){
	freopen("crystal.in","crystal.out",stdin);
	freopen("crystal.in","crystal.out",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		b[a[i]]++;
	}
	sort(a + 1,a + n + 1);
	for(int i = a[1];i <= a[n];i++){
		if(a[i] >= a[1] && a[i] <= a[n]){
			if(b[a[i]] >= maxx){
				maxx = b[a[i]];
				I = i;
				if(b[a[i]] == maxx) I--;
			}
		}
	}	
	if(maxx == 1){
		for(int i = 1;i <= n;i++){
			sum += a[i];
		}
		a[n + 1] = sum / n;
		sort(a + 1,a + n + 2);
		for(int i = 1;i <= n + 1;i++){	
			if(a[i] == sum / n) J = i;
		}
	}
	if(maxx == 1){
		I = J;
		if(a[I + 1] - a[I - 1] >= a[I - 1] - a[I - 2]) I--;
		else I++;
	}
	for(int i = 1;i <= I;i++){
		if(m - a[I] + a[i] >= 0){
			b[a[i]]--;
			b[a[I]]++;
			a[i] = a[I];
		}
		else break;
	}
	maxx = 0;
	for(int i = 1;i <= n;i++) maxx = max(maxx,b[i]);
	cout << maxx;
	return 0;
}
