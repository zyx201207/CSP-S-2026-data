#include<bits/stdc++.h>
#define int long long
using namespace std;
int A[500005];
int B[500005];
signed main() {
//int main() {
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>A[i];
		B[i]=A[i];
	}
	bool flag=true;
	int dn=A[2]-A[1];
	for(int i=3;i<=n;i++){
		if(dn!=A[i]-A[i-1]){
			flag=false;
			break;
		}
	}
	if(flag){
//		cout<<1;
		int C[500005];
		for(int i=1;i<=n;i++){
			C[i]=C[i-1]+i*(i+1)/2;
		}
		int ans;
		for(int i=1;i<=n;i++){
			if(C[i]*dn>m){
				ans=i;
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	int tmp=1;
	int len=n;
	int a=m;
	int bas=A[1];
	while(a){
		len-=1;
		for(int i=1;i<=len;i++){
			B[i]=abs(B[i]-B[i+1]);
		}
		if(a<B[1]*tmp){
			break;
		}
		a-=B[1]*tmp;
		bas+=B[1];
		B[1]=0;
//		cout<<B[1]<<'\n';
		tmp++;
	}
	int tmp2=tmp+1;
//	cout<<bas<<' '<<tmp<<'\n';
	while(A[tmp2]==bas){
		tmp++;
		tmp2++;
	}
	cout<<tmp;
	return 0;
}