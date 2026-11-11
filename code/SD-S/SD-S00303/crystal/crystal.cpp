#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5;
int n,m,cnt;
int a[N];
int s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool A = 0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i] = s[i-1] + a[i];
		if(a[i] != i) A = 1;
	}sort(a+1,a+1+n);
	if(!A){
		for(int i=1;i<=n;i++){
			if(m == s[i+1]){
				cout<<i+2;
				return 0;
			}
			if(m>=s[i] && m<=s[i+1]){
				cout<<i+1;
				return 0;
			} 
		}
		cout<<n;
		return 0;
	}
	for(int i=2;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			bool flag = 0;
			while(cnt <= m){
				if(a[j] == a[i] && cnt<=m){
					flag = 1;
					break;
				}
				a[j]++;cnt++;
				if(a[j] == a[i] && cnt<=m){
					flag = 1;
					break;
				}
			}
//			for(int i=1;i<=n;i++){
//				cout<<a[i]<<" ";
//			}
//			cout<<"*"<<cnt<<"*"<<"i="<<i<<"flag="<<flag<<endl;
			if(!flag){
				cout<<i-1;
				return 0; 
			}
		}
	}
	cout<<n;
	return 0;
}
