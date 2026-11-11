#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,cnt1,cnt2=0,mm;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cnt1=0;
		mm=m;
		for(int j=0;j<=i;j++){
			if(i!=j){
				if(a[i]-a[j]>0 && mm-(a[i]-a[j])>=0){
					cnt1++;
					mm-=(a[i]-a[j]);
				}
			}
		}
		if(cnt1>=cnt2){
			cnt2=cnt1;
		}
	}
	cout<<cnt2+1;
	return 0;
}
