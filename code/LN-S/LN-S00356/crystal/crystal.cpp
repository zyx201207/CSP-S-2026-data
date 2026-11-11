#include<bits/stdc++.h>

using namespace std;

int MAXN=100005;
int n,m;


int main(){
	freopen(crystal.in,"r",stdin);
	freopen(crystal.out,"w",stdout);
	cin>>n>>m;
	int a[MAXN];
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]>a[i+1]){
			swap(a[i],a[i+1]);
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]==a[i+1]){
			ans+=2;
			}
	}
	int add=1;
	for(int i=0;i<n;i++){
		for(int j=add;j<m;j++){
			if(a[i]+j==a[i+1]){
				ans++;
				a[i]=' ';
			}
		}
	}
	cout<<ans;
	return 0;
}
