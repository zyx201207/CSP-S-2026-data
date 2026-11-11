#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N]={};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int ma=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(m==1){
		cout<<ma;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else if(m==2){
		int maa=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>maa) maa=a[i]&a[j];
			}
		}
		cout<<maa;
	}
	
}
