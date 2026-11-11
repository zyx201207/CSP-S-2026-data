#include<bits/stdc++.h>
using namespace std;
int n,m,fl = 1;
int arr[500005],t[300005],a1[300005],sum;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;++i){
		cin >> arr[i];
		if(i >= 2 && arr[i] < arr[i-1]){
			fl = 0;
		}
	}
	if(fl == 1){
		for(int i = 1;i <= m;i++){
			cout << m << " ";
		}
		return 0;
	}
	for(int i = 1;i <= n;i++){
		memset(a1,0,sizeof(a1));
		sum = i;
		for(int j = i;j <= n;j++){
			for(int z = i;z < sum;z++){
				if(arr[j] == a1[z]){
					sum = z;
					break;
				}
			}
			a1[sum] = arr[j];
			sum++;
		}
		for(int i = 1;i <= sum;i++){
			t[a1[i]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << t[i] << " ";
	}
	
	return 0;
}
