#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5;
int yu(int n,int m); 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[N];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum=a[n];
	for(int i=2;i<=m;i++){
		int wer=yu(sum,a[i]);
		sum=wer;
	}
	cout<<sum;
	return 0;
}
int yu(int n,int m){
	int a[1001],b[1001];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	int la,lb;
	la=lb=0;
	while(n!=0){
		a[la++]=n%2;
		n/=2;
	}
	while(m!=0){
		b[lb++]=m%2;
		m/=2;
	}
	la--;lb--;
	int l=max(la,lb);
	int ans[1001];
	for(int i=0;i<=l;i++){
		ans[i]=(a[i]+b[i])/2;
	}
	int summ=0;
	for(int i=0;i<=l;i++){
		int su=1;
		for(int j=0;j<i;j++){
			su*=2;
		}
		summ+=su*ans[i];
	}
	return summ;
}

