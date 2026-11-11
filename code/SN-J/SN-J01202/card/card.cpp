# include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,m;
	cin>>n>>m;
	long long b[m+5]={0},q[n+5]={0};
	vector<long long> a(n+5);
	for(int i=0;i<n;i++){
		cin>>a[i];
		q[i]=1;
	}
	for(int i=0;i<n;i++){
		int z=0;
		for(int j=n-1;j>i;j--){
			if(a[j]==a[i]){
				q[j]+=q[i];
				z=1;
				break;
			}
		}
		if(z==0){
			b[a[i]]+=q[i];
			q[i+1]+=q[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	
	
	return 0;
}
