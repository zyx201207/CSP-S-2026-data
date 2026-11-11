#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],cnt,b[100005],s;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int l=0,r=n-1;
	int mid=l+(r-l)/2;
	for(int i=0;i<n;i++){
		if(a[i]==mid) cnt++;
		if(a[i]<mid) b[i]=m-a[i];
		if(a[i]>mid) b[i]=a[i]-m; 
	}
	for(int i=0;i<n;i++){
		s=b[i];
		if(s==m){
			cnt++;
			break;
		}
		else {
			s+=b[i];
			cnt++;
		}
	}
	cout<<cnt-3;			

	return 0;
} 
