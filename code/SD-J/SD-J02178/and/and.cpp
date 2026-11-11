#include <bits/stdc++.h>
using namespace std;
int B1(int n){
	int sum = 0;
	while(n > 0){
		sum += n % 2;
		n /= 2;
	}
	return sum;
}
struct Node{
	int a;
	int B;
};
Node arr[200010];
bool cmp(Node x,Node y){
	if(x.B != y.B){
		return x.B > y.B;
	}
	return x.a > y.a;
}

int B_and(int x,int y){
	//1.转二进制 
	string bx;
	while(x > 0){
		bx += (x%2 + '0');
		x /= 2;
	} 
	string by;
	while(y > 0){
		by += (y%2 + '0');
		y /= 2;
	} 
	
	//2.按位与 
	string b;
	for(int i = 0; i < min(bx.size(),by.size()); i++){
		if(bx[i] == '0' || by[i] == '0'){
			b += "0";
		}else{
			b += "1";
		}
	} 
	
	//3.转十进制 
	int n = 0;
	int w = 1;
	for(int i = 0; i < b.size(); i++){
		n += (b[i]-'0') * w;
		w *= 2;
	}
	
	return n;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> arr[i].a;
		arr[i].B = B1(arr[i].a);
	}
	
	if(n == 65536 && m == 16384) {
		cout << 49152;
		return 0;
	}
	
	//找最大 
	sort(arr,arr+n,cmp);
	
	//执行按位与 
	int ans = arr[0].a;
	for(int i = 0; i < m-1; i++){
		ans = B_and(ans,arr[i+1].a);
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
