#include<iostream>
using namespace std;
char c[200005];
int a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,len = 0;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> a[i] >> c[i];
		len += a[i];
	}
	int start = 0;
	int end = n-1;
	long long cnt = 0;
	while(start<end){
		if(c[start] != c[end]){
			cnt += min(a[start],a[end]);
		}
		if(a[start] < a[end]){
			a[end] -= a[start];
			a[start] = 0;
			start++;
		}
		else{
			a[start] -= a[end];
			a[end] = 0;
			end--;
		}
	}
	cout << cnt;
	return 0;
}
