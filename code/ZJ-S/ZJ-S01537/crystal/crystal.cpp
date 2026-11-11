#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500011];
bool calc(int M){
	long long sum=0;
	for(int i=1;i<M;i++){
		sum+=(a[M]-a[i]);
		if(sum>m){
			return 0;
		}
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int L=0,R=n+1;
	while(L+1<R){
		int M=(L+R)/2;
		if(calc(M)){
			L=M;
		}
		else{
			R=M;
		}
	}
	cout<<L<<'\n';
	return 0;
}