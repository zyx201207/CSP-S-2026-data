#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long diff[500005];
void quicksort(long long* arr,int l,int r){
	if (l >= r)
		return;
	int i = l,j = r;
	long long pivot = arr[(l + r) / 2];
	while (i <= j){
		while (arr[i] < pivot)
			i += 1;
		while (arr[j] > pivot)
			j -= 1;
		if (i <= j){
			long long temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i += 1;
			j -= 1;
		}
	}
	quicksort(arr,l,j);
	quicksort(arr,i,r);
}
void differ(long long* arr,int n,long long* diff){
	for (int i = 0;i < n;i++){
		if (i == 0)
			diff[i] = 0;
		else
			diff[i] = arr[i] - arr[i - 1];	
	}
}
int bag(long long m,long long* diff,int n){
	int max_ans = 0;
	for (int i = 0;i < n;i++){
		long long cnt = 0;
		int ans = 0;
		for (int j = i;cnt < m && j < n;j++){
			cnt += diff[j];
			ans = j - i;
			if (cnt >= m)
				continue;
		}
		max_ans = (max_ans > ans) ? max_ans : ans;
	}
	return max_ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	scanf("%d %lld",&n,&m);
	for (int i = 0;i < n;i++)
		scanf("%lld",&a[i]);
	quicksort(a,0,n - 1);
	differ(a,n,diff);
	bag(m,diff,n);
	printf("%d",bag(m,diff,n));
	return 0;
}
