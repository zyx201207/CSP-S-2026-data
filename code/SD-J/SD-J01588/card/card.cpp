#include<bits/stdc++.h>
#define CLOSE ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],b[M],c[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	CLOSE
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		stack<int> s;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				s.push(a[j]);
				b[a[j]]=1;
			}
			else{
				while(s.top()!=a[j] && s.empty()==0){
					b[s.top()]=0;
					s.pop();
				}
				s.push(a[j]);
			}
		}
		for(int i=1;i<=m;i++){
			if(b[i]==1){
				c[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
