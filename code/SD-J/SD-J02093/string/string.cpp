#include<bits/stdc++.h>
using namespace std;
long long n,m,k = 0,sum = 0;
char a;
char x[100000005],f[50000005],l[50000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i = 1;i <= n;i++){
		cin>>m>>a;
		for (int j = 0; j < m;j++){
			x[k] = a;
			k++;
		}
	}for (int i = 0;i < k/2;i++){
		f[i] = x[i];
	}int t= 0;
	for (int i = k-1;i > k/2;i--){
		l[t] = x[i];
		t++;
	}for (int i = 0;i < k/2;i++){
		if (f[i] != l[i]){
			sum++;
		}
	}cout<<sum;
	return 0;
}
