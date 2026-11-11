#include<bits/stdc++.h>
using namespace std;
long long a[5000100],v[5000100],w[5000100];
long long m,n;
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	stack<long long> q; 
	for(long long i=1;i<=n;i++){
		cin >> a[i];
	}
	memset(v,0,sizeof(v));
	memset(w,0,sizeof(w));
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(w[a[j]]==0) {
				q.push(a[j]);
				w[a[j]]=1;
			}
			else{
				while(q.top()!=a[j]){
					w[q.top()]=0;
					q.pop();
				}
			}
		}
		while(!q.empty()){
			v[q.top()]++;
			w[q.top()]=0;
			q.pop();
		}
	}
	for(long long i=1;i<=m;i++){
		cout << v[i] << " ";
	}
	return 0;
}
