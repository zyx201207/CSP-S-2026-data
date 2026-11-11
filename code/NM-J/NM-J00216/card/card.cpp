#include <bits/stdc++.h>
using namespace std;

long long int n,m,arr[10000000],brr[10000000],crr[10000000];
long long int _right = 1;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;++i){
		cin >> arr[i];
	}
	for(int l = 1;l<=n;++l){
		_right = l;
		for(int i = l;i<=n;++i){
			brr[_right++] = arr[i];
			for(int j = l;j<=m;++j){
				if(brr[j]==brr[_right-1]){
					_right = j+1;
					break;
				}
			}
		}
		
		for(int i = 1;i<_right;++i){
			if(brr[i]!=0){
				crr[brr[i]]++;
			}
		}
		fill(brr,brr+n+1,0);
	}

	for(int i = 1;i<=m;++i){
		cout << crr[i] << " ";
	}
	return 0;
}

