#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[300005];
bool A=true;
stack<int> d,e;
bool b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i]){
			A=false;
		}
	}
	if(A){
		for(int i=n;i>=1;i--){
			if(!b[a[i]]){
				b[a[i]]=true;
				d.push(a[i]);
			}
			else{
				while(d.top()!=a[i]){
					b[d.top()]=false;
					d.pop();
				}
			}
			while(!d.empty()){
				e.push(d.top());
				c[d.top()]++;
				d.pop();
			}
			while(!e.empty()){
				d.push(e.top());
				e.pop();
			}
		}
	}
	else{
		for(int l=1;l<=n;l++){
			for(int i=l;i<=n;i++){
				if(b[a[i]]){
					while(!d.empty()&&d.top()!=a[i]){
						b[d.top()]=false;
						d.pop();
					}
				}
				else{
					b[a[i]]=true;
					d.push(a[i]);
				}
			}
			while(!d.empty()){
				c[d.top()]++;
				d.pop();
			}
			memset(b,0,sizeof b);
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
