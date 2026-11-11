#include<bits/stdc++.h>
using namespace std;
int a[1000100];
int b[1000100];
int c[1000100];
stack<int>stk;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int k=1;k<=n;k++){
		memset(b,0,sizeof b);
		for(int i=k;i<=n;i++){
			if(b[a[i]]>=1){
				while(!stk.empty()&&stk.top()!=a[i]){
					b[stk.top()]--;
					stk.pop();
				}
			}else{
				stk.push(a[i]);
				b[a[i]]++;
			}
		}
		for(int j=1;j<=m;j++){
			if(b[j]>=1)
				c[j]++;
			
		}
	}
	for(int i=1;i<=m;i++)cout << c[i] << ' ';
	return 0;
}
