#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int a[500010],b[300010];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> s;
		int c[300010];
		for(int j=i;j<=n;j++){
			while(c[a[j]]>0&&!s.empty()){
				if(s.top()==a[j]){
					c[a[j]]--;
				}
				s.pop();
			}
			s.push(a[j]);
		}
		while(!s.empty()){
			b[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
