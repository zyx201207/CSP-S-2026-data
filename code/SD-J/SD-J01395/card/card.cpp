#include<bits/stdc++.h>
using namespace std;
long long ma[200010];
long long rt[200010];
stack<long long> v;
long long atx[200010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>atx[i];
	}
for(long long k=0;k<n-1;k++){
	for(long long i=k;i<n;i++){
		long long x=atx[i];
		v.push(x);
		if(ma[x]==0){
			ma[x]=i;
		}else{
			while(v.top()==x){
				ma[v.top()]=-1;
				v.pop();
			}
			ma[x]=i;
		}
		
	}
	for(long long l=0;l<v.size();l++){
		rt[v.top()]++;
		v.pop();
	}
	memset(ma,0,sizeof(ma));
}
	rt[atx[n-1]]++;
	for(long long i=1;i<=m;i++){
		cout<<rt[i]<<" ";
	}
	return 0;
}

