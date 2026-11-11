#include <bits/stdc++.h>
using namespace std;
void fre(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
}
long long n,m,a[200010];
long long ans[300010];
bool f[300010];
stack <int> s;
int main(){
	fre();
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[a[j]]==1){
				while(s.top()!=a[j]){
					f[s.top()]=0;
					s.pop();
				}
				f[s.top()]=0;
				s.pop();
			}
			s.push(a[j]);
			f[a[j]]=1;
		}
		while(!s.empty()){
			f[s.top()]=0;
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
