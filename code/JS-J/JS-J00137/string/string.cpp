#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio();
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum=0;
	string yc,fc;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		sum+=a;
		for(int i=1;i<=a;i++){
			yc+=c;
		}
	}
	long long num=0;
	for(long long i=0;i<sum;i++){
		if(yc[i]!=yc[sum-i-1]) num++;
	}
	cout<<num/2;
	return 0;
}
