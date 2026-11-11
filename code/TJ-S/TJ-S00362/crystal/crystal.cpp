#include<bits/stdc++.h>
using namespace std;
long long m,n,ni=0;
long long nl[500005][20],a[500005];
int f(int k){
	long long cnt=nl[k][1],mi=m,i=k-1;
	while(mi>0&&i>=0){
		int x=nl[k][0]-nl[i][0];
		int y=min(mi/x,nl[i][1]);
		cnt+=y;mi-=y*x;
		i--;
	}
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n);
	nl[0][0]=a[0];nl[0][1]=1;
	for(int i=1;i<n;i++){
		if(a[i]!=nl[ni][0]){
			nl[++ni][0]=a[i];
		}
		nl[ni][1]++;
	}int maxn=0;
	for(int i=ni;i>=0;i--){
		maxn=max(maxn,f(i));
	}cout<<maxn;
	return 0;
}
