#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int main(){
	freopen("card.in","r",stdin);
	int n,m,a[N],b[N],c[N],cc=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		queue<int> p;
		p.push(a[1]);
		c[cc]=a[1];
		cc++;
		for(int j=i;j<=n;j++){
			bool flag=0;
			for(int q=1;q<=i;q++){
				if(a[j]==a[q]){
					flag=1;
					continue;
				}
			}
			if(flag==0){
				p.push(a[j]);
				c[cc]=a[j];
				cc++;
			}
			else{
				for(int q=1;q<=i;q++) p.pop();
				for(int q=1;q<=cc;q++) c[q]=0;
				cc=1;
				p.push(a[j]);
				c[cc]=a[j];
				cc++;
			}
		}
		int cd=1;
		while(p.empty()){
			int d=c[cd];
			b[d]++;
			p.pop();
			cd++;
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<' ';
	freopen("card.out","w",stdout);
	return 0;
}
