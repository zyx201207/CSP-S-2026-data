#include<bits/stdc++.h>
using namespace std;
long long n;
struct node{
	long long x;
	char c;
}a[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	long long num = 0;
	for(int i = 1;i <= n;i++){
		long long X;
		char C;
		cin >> X >> C;
		if(C != a[num].c){
			num++; 
		}
		a[num].x += X;
		a[num].c = C;
	}
	long long L = 1 , R = num , sum = 0;
	while(L < R){
		if(a[L].x > a[R].x){
			if(a[L].c != a[R].c){
				sum += a[R].x;
			}
			a[L].x -= a[R].x;
			a[R].x = 0;
			R--;
		}
		else if(a[L].x < a[R].x){
			if(a[L].c != a[R].c){
				sum += a[L].x;
			}
			a[R].x -= a[L].x;
			a[L].x = 0;
			L++;
		}
		else{
			if(a[L].c != a[R].c){
				sum += a[L].x;
			}
			a[L].x = 0;
			a[R].x = 0;
			L++;
			R--;
		}
	}
	cout << sum;
	return 0;
}
