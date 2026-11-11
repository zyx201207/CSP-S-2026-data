#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200002];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=0,r=pow(2,30);
	while(l<r-1){
		int mid=l+(r-l)/2;
		int num=0;
		for(int i=1;i<=n;i++){
			if((a[i]&mid)==mid) num++;
		}
		if(num<m) r=mid;
		else l=mid;
	}
	cout<<l;
	return 0;
}
