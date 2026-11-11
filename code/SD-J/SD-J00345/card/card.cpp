#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],c[500005],b[300005];
stack<int>s;
void f(int x){
	while(!s.empty()){
		s.pop();
	}
	memset(b,0,sizeof(b));
	for(int i=x;i<=n;i++){
		if(!b[a[i]]){
			b[a[i]]++;
			s.push(a[i]);
		}
		else{
			while(!s.empty()){
				if(s.top()==a[i])break;
				b[s.top()]=0;
				s.pop();
			}b[a[i]]=1;
		}
	}
	for(int i=1;i<=m;i++){
		if(b[i])c[i]++;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		f(j);
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 
