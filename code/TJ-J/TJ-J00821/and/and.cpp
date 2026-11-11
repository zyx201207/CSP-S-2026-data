#include<bits/stdc++.h>
using namespace std;
struct cmp(int x,int y){
	return x > y;
};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
	int a,b,count[],num[],ans[],member = 0;
	cin >> a >> b;
	for (int i = 1;i <= a;i ++){
		cin >> arr[i];
	}
	sort(arr,arr+a,cmp);
	int j = 1,h = 1;
	while (arr[1]){
			count[j] = arr[1] % 2;
			arr[i] /= 2;
			j += 1;
		}
	while (arr[2]){
		num[j] = arr[2] % 2;
		arr[i +1] /= 2;
		h += 1;
	}
	for (int i = max(num.size(),count.size());i >= 1;i --){
		if (num[i] == count[i] && num[i] == 1){
			ans[i] = 1;
		}
	}
	for (int i = min(num.size(),count.size());i >= 1;i ++){
		member += 2^i*i; 
	}
	cout << member;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
