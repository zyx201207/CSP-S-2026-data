#include<bits/stdc++.h>
using namespace std;
int a[1234567],n,m,c,answer=1,ma=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	c=m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		c=m;
		answer=0;
		for(int j=i-1;j>=0;j--){
			if(a[i]-a[j]>=c){
				answer++;
				c-=a[i]-a[j];
			}
		}
		ma=max(answer,ma);
	}
	cout<<ma;
	return 0;
}