#include<bits/stdc++.h>
using namespace std;
long long a;//多少个数
long long b;//多少个字母
long long num,sum=0;//一共有多少个,除二 
char c;//字母 
string n,m;//n表示正序m表示倒序 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> a;
	for(int i = 1;i<=a;i++){
		cin >> b >>c;
		for(int j = 1; j <=b;j++){
			n+=c;
		}
		num+=b; 
	}
	for(int i = num-1; i >= 0; i--){
		m += n[i];
	}
	for(int i = 0; i <= num-1;i++){
		if(n[i] != m[i]){
			sum+=1;
		}
	}
	sum/=2;
	cout << sum;
	return 0;
} 
