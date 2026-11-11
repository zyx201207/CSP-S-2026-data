#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char a[1000005];
	int n;
	cin>>n;
	int sum=0;
	int ii=0;
	for(int i=0;i<n;i++){
		int num;
		char c;
		cin>>num>>c;
		for(int j=0;j<num;j++){
			a[ii]=c;
			ii++;
		}
		sum+=num;
	}
	int q=sum/2;
	int p=sum/2;
	if(sum%2==0){
		p--;
	}
	int cnt=0;
	while(1){
		if(a[p]!=a[q]){
			cnt++;
		}
		p--;
		q++;
		if(p<0){
			break;
		}
	}
	cout<<cnt;
	return 0;
}
