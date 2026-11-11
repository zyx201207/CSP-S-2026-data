#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

LL n,m,a[500005];
unordered_map<LL,LL>num_of_a,num_after_a;

int main() {

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin>>n>>m;
	for(LL i=1; i<=n; i++) {
		cin>>a[i];
		mp[a[i]]++;
	}

	sort(a+1,a+1+n);

//	LL last_num=a[1];
//	bool dengchashulie=true;
//	if(n=1) {
//		cout<<1;
//		return 0;
//	}
//	LL gongcha=a[2]=a[1];
//	for(LL i=2; i<=n; i++) {
//		if(last_num!=a[i]) {
//			num_after_a[a[i-1]]=a[i];
//			last_num=a[i];
//		}
//		if(a[i]-a[i-1]!=gongcha) {
//			dengchashulie=false;
//		}
//	}
//	if(dengchashulie){
//		for(LL i=1;i<=n;i++){
//			
//		}
//	}
//
//	LL maxx_in_num_of_a=-0x3f3f3f3f3f3f3f3f;
//
//	for(LL i=1; i<=n; i++) {
//		
//	}
	
	cout<<m;
	return 0;
}

