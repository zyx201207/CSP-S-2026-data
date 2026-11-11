#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int maxx=INT_MIN;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(maxx<a[i]&a[j] and i!=j and i>=0&&j>=0){
					maxx=a[i]&a[j];
				}
			}
		}
		cout<<maxx<<endl;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(maxx<a[i] and i>=0){
				maxx=a[i];
			}
		}
		cout<<maxx;
		return 0;
	}
	if(n==m){
		for(int i=1;i<=n-1;i++){
			if(i>=0){
			sum+=a[i]&a[i+1];
		}
		}
		cout<<sum;
		return 0;
	}
	return 0;
}
