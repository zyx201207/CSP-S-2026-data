#include <bits/stdc++.h>
using namespace std;
int n;
int shui[500005];
int jing(long long m){
	int sum=0;
	for(int i=n;i>=1;i--){
		long long num=0;
		for(int j=i-1;j>=1;j--){
			num+=shui[i]-shui[j];
			if(num==m){
				sum=max(sum,i-j+1);
				break;
			}else if(num>m){
				sum=max(sum,i-j);
				break;
			}
		}
	}
	return sum;
}
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>shui[i];
	}
	sort(shui+1,shui+n+1);
	cout<<jing(m);
	return 0;
}
