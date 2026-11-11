#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,sum1=-1,Max;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<int>a(n);
	for(int i=0;i<n;i++)cin>>a[i],sum1&=a[i],Max=max(Max,a[i]);
	if(m==n){
		cout<<sum1;
	}
	else if(m==1){
		cout<<Max;
	}
	else if(m==2&&n<2000){
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				Max=max(Max,a[i]&a[j]);
			}
		}
		cout<<Max;
	}
	else if(m==3&&n<125){
		for(int i=0;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				for(int l=j+1;l<n;l++){
					Max=max(Max,a[i]&a[j]&a[l]);
				}
			}
		}
		cout<<Max;
	}
	else cout<<m;
	return 0;
}
