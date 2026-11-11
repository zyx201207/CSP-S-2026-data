#include<bits/stdc++.h>

using namespace std;
const int N=5e5+5;
int A[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,maxn=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	sort(A,A+n);
	for(int i=0;i<n;i++){
		int sum=1,ans=m;
		for(int j=i-1;j>=0;j--){
			if(ans>=(A[i]-A[j])){
				sum++;
				ans-=(A[i]-A[j]);
			}
			else break;
		}
		maxn=max(maxn,sum);
	}
	cout<<maxn;
	return 0;
}