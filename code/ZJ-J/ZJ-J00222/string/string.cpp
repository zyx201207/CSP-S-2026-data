#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

long long n,cnt,sum;

struct node{
	int x;
	string c;
}a[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].x >> a[i].c;
		sum += a[i].x;
	}
	int i = 1,j = n;
	while(i < j){
		if(a[i].c == a[j].c){
			if(a[i].x > a[j].x){
				a[i].x -= a[j].x;
				j--;
			}else if(a[i].x < a[j].x){
				a[j].x -= a[i].x;
				i++;
			}else{
				i++;
				j--;
			}
		}else{
			if(a[i].x > a[j].x){
				a[i].x -= a[j].x;
				cnt += a[j].x;
				j--;
			}else if(a[i].x < a[j].x){
				a[j].x -= a[i].x;
				cnt += a[i].x;
				i++;
			}else{
				cnt += a[i].x;
				i++;
				j--;
			}
		}
	}
	cout << cnt;
	
	
	return 0;
}
