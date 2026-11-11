#include<iostream>
#include<cstdio>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,shu=0,shumax=0;
	long long m,ans=1;
	cin >> n >> m;
	vector<long long> a(n),b(n+1);
	int dp[100][100]={0};
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(i==0){
			b[i]=a[i];
		}
		else{
			b[i]=a[i]-a[i-1];
			if(b[i]==b[i-1]){
				shu++;
			}
			else{
				shumax=max(shumax,shu);
				shu=0;
			}
		}
	}
	shu=max(shumax,shu);
	if(shu>=n-2){
		long long bu=m/b[1],sum=0;
		for(long long i=1;;i++){
			sum+=i;
			if(sum>bu){
				cout << i;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
