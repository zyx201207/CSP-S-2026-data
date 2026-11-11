#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200005;
int n,m,a[N][35];
ll pa[35];
ll asd=1,sum=0;
void dfs(int jj,vector<int > asd){
	vector<int > vec;
	int a_sum[35]={0};
	for(int i=0;i<asd.size();i++){
		for(int j=jj-1;j>=0;j--){
			a_sum[j]+=a[asd[i]][j];
		}
	}
	for(int j=jj-1;j>=0;j--){
		if(a_sum[j]>=m){
			for(int i=0;i<asd.size();i++){
				if(a[asd[i]][j]){
					vec.push_back(asd[i]);
				}
			}
			dfs(j,vec);
			sum+=pa[j];
			break;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=0;i<=32;i++){
		pa[i]=asd;
		asd*=2;
	}
	cin>>n>>m;
	vector<int > qwe;
	for(int i=1;i<=n;i++){
		ll asd;
		qwe.push_back(i);
		cin>>asd;
		int j=0;
		while(asd>0){
			a[i][j]+=asd%2;
			asd/=2;
			j++;
		}
	}
	dfs(32,qwe);
	cout<<sum<<endl;
	return 0;
}
