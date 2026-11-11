#include<bits/stdc++.h> 
using namespace std;
const int N=5e5+10;
long long arr[N],brr[N],gh,p=-1,ji;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	for(int i=2;i<=n;i++){
		brr[i]=arr[i]-arr[i-1];
	}
	for(int i=2;i<=n;i++){
		gh=0,ji=0;
		int l=i,r=i+1;
		while(l>=2&&r<=n&&gh<=m){
			if(brr[l]<brr[r]){
				gh+=brr[l];
				ji++;
				l--;
			}
			else if(brr[l]>brr[r]){
				gh+=brr[r];
				ji++;
				r++;
			}
		}
		if(gh>m){
			p=max(p,ji);
		}
		else p=max(p,ji+1);
	}
	cout<<p;
	return 0;
}
