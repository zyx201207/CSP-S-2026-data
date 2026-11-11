#include<bits/stdc++.h> 
using namespace std;

int main(){
	freopen("subay.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,f;
	cin>>c>>f;
	int n,d;
	cin>>n>>d;
	int num[2000005];
	int sum[2000005];
	for(int i=0;i<=n;i++){
		cin>>num[i];
	}
	for(int i=2;i<=n;i++){
		sum[i]=sum[i]=sum[i-1];
	}
	cout>>0;
	return 0;
}
