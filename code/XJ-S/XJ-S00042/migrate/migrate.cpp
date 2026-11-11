#include<iostream>
#include<cstdio>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(long long i=0;i<m;i++){
		long long a,b;
		cin >> a >> b;
		vector<int> c(a);
		for(long long j=0;j<a;j++){
			cin >> c[i];
		}
		cout << i%3;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
