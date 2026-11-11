#include <bits/stdc++.h>
using namespace std;

long long n,m,_left,_right,_mid;
long long arr[10000005],brr[10000005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;++i){
		cin >> arr[i];
	}
	
	sort(&arr[1],&arr[n+1]);
	for(int i = 1;i<=n;++i){
		brr[i] = brr[i-1]+arr[i];
	}
	
	_left = 1;
	_right = n;
	
	while(_left<=_right){
		int flag = 0;
		_mid = _left+(_right-_left)/2;
		
		for(int i = _mid;i<=n;++i){
			if(arr[i]*(_mid-1)-brr[i-1]+brr[i-_mid]<=m){
				flag = 1;
				break;
			}
		}
		if(flag==1){
			_left = _mid+1;
		}else{
			_right = _mid-1;
		}
	}
	cout << _right;
	return 0;
}

