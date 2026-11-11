#include<bits/stdc++.h>

using namespace std;

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int n;
	long long m;
	cin>>n>>m;
	vector<long long> a(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end());
	int cnt=0;
	for(int i=1;i<=n;i++){
		vector<long long> cz(i+1,0),pre(i+1,0);
		for(int j=i-1;j>=1;j--){
			cz[j]=a[i]-a[j];
		}
		for(int j=1;j<=i-1;j++){
			pre[j]=pre[j-1]+cz[j];
		}
		for(int l=1;l<i;l++){
			for(int r=l+1;r<i;r++){
				if(pre[r]-pre[l-1]<=m){
					cnt=max(cnt,r-l+1+1);
				}
			}
		}
	}
	cout<<cnt<<'\n';
	
	return 0;
}
