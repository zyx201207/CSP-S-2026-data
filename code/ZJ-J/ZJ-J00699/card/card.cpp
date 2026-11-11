#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=5e5+5;
ll n,m,a[N],sum[N];
int main(){
	
	freopen("card.in""r""stdin");
	freopen("card.out""w""stdout");
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		int s[300005]={0};
		for(int i=j;i<=n;i++){
			
			if(s[a[i]]!=0){
				for(int k=s[a[i]];k<i;k++) s[a[k]]=0;
			}
			s[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			if(s[i]!=0) sum[i]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<' ';
	return 0;
} 
