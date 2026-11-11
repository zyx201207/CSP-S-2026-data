#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500004],pp[500005];
long long p[500005]={0};
stack<int>op;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(p,0,sizeof p);
		for(int j=i;j<=n;j++){
			if(p[a[j]]){
				while(op.size()&&op.top()!=a[j]){
					p[op.top()]=0;
					op.pop();
				}
				op.pop();
				op.push(a[j]);
				
			}
			else{
				p[a[j]]=1;
				op.push(a[j]);
			}
		}
		while(!op.empty()){
//			cout<<op.top()<<' ';
			pp[op.top()]++;
			op.pop();
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",pp[i]);
	}
	return 0;
}
