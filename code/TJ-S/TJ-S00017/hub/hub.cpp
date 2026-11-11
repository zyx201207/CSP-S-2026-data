#include <bits/stdc++.h>
using namespace std;

#define LL long long

LL c,t,in_[2000005],out_[2000005];

int main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	for(LL i = 1;i <= t;i++){
		LL n,k,sum = 0;
		cin>>n>>k;
		for(LL j = 1;j < n;j++){
			cin>>in_[i]>>out_[i];
			if(sum <= 65) sum += abs(in_[i] - out_[i]);
		}
		cout<<n * t / sum<<endl;
	}
	
	return 0;
}
