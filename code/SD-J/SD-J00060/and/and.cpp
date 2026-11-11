#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ms=INT_MIN;
bool cmp(int a,int b){
	return a>b; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
	}
	else if(m==n){
		int s=1;
		for(int i=1;i<=n;i++){
			s=s&a[i];
		}
		cout<<s;
	}
	else if(m==n-1){
		int s=1;
		for(int i=1;i<n;i++){
			s=s&a[i];
		}
		cout<<s;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ms=max(ms,a[i]&a[j]);
			}
		}
		cout<<ms;
	}
	else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					ms=max(ms,a[i]&a[j]&a[k]);
				} 
			}
		}
		cout<<ms;
	}
	else if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int h=k+1;h<=n;h++){
						ms=max(ms,a[i]&a[j]&a[k]&a[h]);
					}
				} 
			}
		}
		cout<<ms;
	}
	else if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int h=k+1;h<=n;h++){
						for(int w=h+1;w<=n;w++){
							ms=max(ms,a[i]&a[j]&a[k]&a[h]);
						}
					}
				} 
			}
		}
		cout<<ms;
	}
	else{
		int s=1;
		for(int i=1;i<=m;i++){
			s=s&a[i];
		}
		cout<<s;
	}
	return 0;
}
