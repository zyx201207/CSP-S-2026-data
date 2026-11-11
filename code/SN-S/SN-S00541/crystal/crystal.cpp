#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100010],b[100010],k=10000;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		b[i]=0;
	}
	for(int i=0;i<n;i++){
		int s=m-1;
		for(int j=-k;j<=k;j++){
			if(a[i]==j){
				b[j+k]++;
			}else if(a[i]==j-m+s&&s>=0){
				b[j+k]++;
				s--;
			}
		}
	}
	long long ans=0;
	for(int i=0;i<=k*2;i++){
		if(b[i]>ans){
			ans=b[i];
		}
	}
	cout<<ans;
	return 0;
}
