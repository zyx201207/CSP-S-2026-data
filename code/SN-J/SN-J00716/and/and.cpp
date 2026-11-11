//王楷淳 SN-J00716 西安交通大学附属中学 
#include <bits/stdc++.h>
using namespace std;
long long n,k,s;
long long arr[1000005];
int main(){
	freopen("and.in ","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> arr[i];
	}
	sort(arr+1,arr+n+1);
	int j = 1,s = arr[n];
	for(int i = n-1;i > n-k;i--){
		s = s & arr[i];
	}
	cout << s << " ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
