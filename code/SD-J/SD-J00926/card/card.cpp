#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
long long k[500005];
stack<long long> c;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){	
		memset(b,0,sizeof(b));
		for(long long j=i;j<=n;j++){
			b[a[j]]++;
//			if(b[a[j]]==c.top()){
//				c.pop();
//				b[a[j]]--;
//			}
			if(b[a[j]]>=2){
				while(c.top()!=a[j])
				{
					b[c.top()]--;
					c.pop();
				}
				c.pop();
				b[a[j]]--;
			}
			c.push(a[j]);
		}
		while(!c.empty()){
			k[c.top()]++;
			c.pop();
		}
	}
	for(long long j=1;j<=m;j++){
		cout<<k[j]<<" ";	
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
