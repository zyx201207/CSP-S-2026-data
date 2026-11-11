#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],sum[N];
bool f[N];
stack<long long>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=0;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			long long h=a[j];
			if(f[h]){
				while(q.top()!=h){
					f[q.top()]=0;
					q.pop();
				}
			}
			else{
				q.push(h);
				f[h]=1;
			}
		}
		for(int k=1;k<=m;k++){
			if(f[k]){
				sum[k]++;
				f[k]=0;
			}
		}
		while(!q.empty())q.pop(); 
	}
	for(long long i=1;i<=m;i++)cout<<sum[i]<<' ';
	return 0;
} 

