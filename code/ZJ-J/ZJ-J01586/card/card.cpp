#include<bits/stdc++.h>
using namespace std;
long long a[500010],f[500010],book[500010],n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		stack<int> s;
		memset(book,0,sizeof book);
		for(int j=i;j<=n;j++){
			if(!book[a[j]]) s.push(a[j]),book[a[j]]++,f[a[j]]++;
			else{
				while(s.top()!=a[j]){
					int t=s.top();
					s.pop();
					book[t]--;
					f[t]--;
				}
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<f[i]<<" ";
	return 0;
}
