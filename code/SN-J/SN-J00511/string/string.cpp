#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long cnt,sum[N];
int a[N];
char c[N];
int n,fa=1,f=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(a[i]<500) fa=0;
		sum[i]=sum[i-1]+a[i];
		cnt+=a[i];
		if(i!=1&&c[i]!=c[i-1]) f=0;
	}
	if(fa==0){
		cout<<cnt/2;
		return 0;
	}
	if(f==1){
		cout<<0;
		return 0;
	}
	cnt=0;
	for(int i=1;i<=n;i++){
		char x;
		int len=n-i;
		for(int j=n;j>=1;j--){
			if(sum[j]<=len){
				len=j;
				break;
			}
		}
		if(c[len]!=c[i]){
			cnt+=a[i];
		}
	}
	cout<<cnt;
	return 0;
}
