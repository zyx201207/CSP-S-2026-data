#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long a[n]={}, b[n]={};
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	b[0]==1;
	for(int i=0;i<m;i++){
		a[0]++;
		if(a[0]>a[1]){
			swap(a[0],a[1]);swap(b[0],b[1]);
			if(b[0]==0) b[0]=1;
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]==a[i+1]){
			b[i]=1;
			b[i+1]=1;
		} 
		else a[i]=1;
	}
	for(int i=0;i<n;i++){
		if(b[i]==1){
			cnt++;
		} 
	}
	cout<<cnt;
	return 0;
	//ÄÌÍÞºÃ¿´£¬Âå¹ÈNansen__weber; 
}
