#include<bits/stdc++.h>
using namespace std;
#define long long ll
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int f=a[1];
	ll cnt=0;
	for(int l=1;l<=n;l++){
		if(f!=a[l]){
			cout<<cnt<<" ";
			cnt++;
			f=a[l];
		}else{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
