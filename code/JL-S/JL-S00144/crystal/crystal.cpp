#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000005],q,sum,b[1000005],sum1,d[1000005],e;
vector<int> v;
void dfs(long long l,long long c,long long q){
	if(l>=n){
		for(int i=0;i<n;i++){
			if(b[i]==q)continue;
			if(b[i]==0){
				sum1++;
				continue;
				}
			sum+=(q-b[i]);
			}
			if(sum==m){
				d[e]=(n-sum1);
				e++;
				}
			sum=0;
			sum1=0;
		return;
	}else{
		for(int i=0;i<=1;i++){
			if(i==0){
				b[c]=a[l];
				dfs(l+1,c+1,q);
				}
			if(i==1){
				b[c]=0;
				dfs(l+1,c,q);
			}
			}
	}
	}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		dfs(0,0,a[i]);
		}
	sort(d,d+e,greater<int>());
		cout<<d[0];
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
