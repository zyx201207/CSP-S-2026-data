#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	string all;
	int k=n; 
	while(k--){
		long long a;
		char c;
		cin>>a>>c;
		for(long long i=0;i<a;i++){
			all+=c;
		}
	}
	long long num=0;
	for(int i=0;i<=n/2;i++){
		for(int j=n-1;j>=n/2;j--){
			if(all[j]!=all[i]){
				num++;
			}
		}
	}
	cout<<num;
	return 0;
}
