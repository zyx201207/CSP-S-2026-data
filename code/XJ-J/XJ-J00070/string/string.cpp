#include<iostream>
#include<cstdio>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,minn;
	cin >> n;
	long long ans=0,mina=1000000001,gys=1;
	vector<long long> a(n);
	vector<char> b(n),c;
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i];
		if(mina>a[i]){
			mina=a[i];
			minn=i;
		}
	}
	for(long long i=2;i<=mina;i++){
		bool pd=true;
		while(pd){
			for(int j=0;j<n;j++){
				if(a[j]%i!=0||a[j]<i){
					pd=false;
					break;
				}
			}
			if(pd){
				for(int j=0;j<n;j++){
					a[j]/=i;
				}
				gys*=i;
			}
		}
		mina=min(mina,a[minn]);
	}
	for(int i=0;i<n;i++){
		for(long long j=0;j<a[i];j++){
			c.push_back(b[i]);
		}
	}
	for(long long i=0;i<c.size()/2;i++){
		if(c[i]!=c[c.size()-1-i]){
			ans++;
		}
	}
	cout << ans*gys;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
