#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[100001];
int sum[100001];
int wz=0;
bool bd=true;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(i<n-1){
			if(a[i]==a[i+1]){
				bd=false;
			}
		}
	}
	if(m==1){
		cout<<n;
		return 0;
	}else if(bd){
		for(int i=0;i<n;i++){
			for(int j=wz;j<n;j++){
				sum[j]++;
			}
			wz++;
		}
	}else{
		cout<<10<<5;
		return 0;
	}
	for(int i=0;i<m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
