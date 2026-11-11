#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
stack<int>s;
bool b[N];
int a[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1;
	while(l<=n){
		memset(b,0,sizeof(b));
		for(int i=l;i<=n;i++){
			if(b[a[i]]){
				while(s.top()!=a[i]){
					int c=s.top();
					b[c]=0;
					s.pop();
				}
			}else{
				s.push(a[i]);
				b[a[i]]=1;
			}
		}
		for(int i=1;i<=m;i++){
			if(b[i])ans[i]++;
		}
		l++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
