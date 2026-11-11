#include<bits/stdc++.h>
using namespace std;
string s; 
int main(){
	freopen("string.in","a",stdin);
	freopen("string.out","b",stdout);
	long long int n;
	cin >> n;
	int a[1000000005],ans = 0;
	string b[1000000005];
	for(int i = 0;i < n;i++){
		cin >> a[i],b[i];
	}
	int around = 0;
	for(int i = 0;i < n;i++){
		around += a[i];
	}
	for(int i = 0;i < n;i++){
		int j;
		for(j = 0;j < a[i];j++){
			
		}
	}
	return 0;
}
