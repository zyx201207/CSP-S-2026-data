#include<bits/stdc++.h>
using namespace std;
long long n,len111[200010],l,r,cnt = 0,sum111[20010];
char zimu111[200010];
char find_xiabiao(int a){
	for(int i = 1;i <= n;i++){
		if(a < sum111[i]){
			return zimu111[i];
		}
	}
	return 'a';
}
int main(){
	cin >> n;
	sum111[0] = 0;
	for(int i = 1;i <= n;i++){
		cin >> len111[i] >> zimu111[i];
		sum111[i] = sum111[i - 1] + len111[i];
	}
	l = 0;
	r = sum111[n] - 1;
	while(l < r){
		if(find_xiabiao(l) != find_xiabiao(r))cnt += 1;
		l++;
		r--;
	}
	cout << cnt;
	return 0;
}