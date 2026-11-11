#include <bits/stdc++.h>
using namespace std;

int a[500005],b[500005];

void _clean(int num){
	for (int s = 1;s<= num;s++) b[s]=-1;
}

int main(){
	int n,m;
	cin>>n>>m;
	for (int i = 1;i <= n;i++) cin>>a[i];
	for (int i = 1;i <= n;i++){
		int cnt = 0;
		int k = 1;
		for (int j = i;j <= n;i++){
			int w =0;
			for (int l = 1;l <= k;l++){
				if (b[l]==a[j]){
					for (int ij = l+1;ij<=k;ij++) b[ij] = -1;
					w = 1;
					k=l+1;
				}
			} 
			if (w==0){
				b[k] =  a[j];
				k++;
			} 
		}
		for (int j = 1;j <= n;j++) if (b[j]==a[i]) cnt++;
		cout<<cnt<<" ";
		_clean(n-i+1);;
	}
	return 0;
}
