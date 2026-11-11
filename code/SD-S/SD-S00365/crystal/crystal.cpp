#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500025],sum,cha[500025];
bool cmp(int a,int b){
	return a<b;
}
int final;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<n;i++){
		cha[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n;i++){
		sum+=cha[i];
		if(sum<=m&&sum+cha[i+1]>m){
			cout<<i+1;
			return 0;
		}
	}
	return 0;
}

