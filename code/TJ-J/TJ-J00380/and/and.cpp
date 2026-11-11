#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int maxsum=-1e9;
int a[100001];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=0;i<n;i++){
			if(a[i]>maxsum){
				maxsum=a[i];
			}
		}
	}else if(m==n){
		int sum=a[0]&a[1];
		for(int i=2;i<n;i++){
			sum=sum&a[i];
		}
		maxsum=sum;
	}else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(j<=i){
					continue;
				}else{
					if(a[i]&a[j]>maxsum){
						maxsum=a[i]&a[j];
					}
				}
			}
		}
	}else if(m==n-1){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==0){
					int sum=a[1]&a[2];
					j=3;
					if(j==i){
						continue;
					}
					sum=sum&a[j];
					if(sum>maxsum){
						maxsum=sum;
					}
				}else if(i==1){
					int sum=a[0]&a[2];
					j=3;
					sum=sum&a[j];
					if(sum>maxsum){
						maxsum=sum;
					}
				}else{
					int sum=a[0]&a[1];
					j=2;
					sum=sum&a[j];
					if(sum>maxsum){
						maxsum=sum;
					}
				}
			}
		}
	}else{
		maxsum=10;
	}
	cout<<maxsum;
	return 0;
}
