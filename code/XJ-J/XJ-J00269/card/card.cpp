#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m,a[N],t[M],sum[M];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof(t));
		for(int j=i;j<=n;j++){
			while(!s.empty()&&t[a[j]]==1){
				int tmp=s.top();
				s.pop();
				t[tmp]=0;
			}
			s.push(a[j]);
			t[a[j]]=1;
		}
		while(!s.empty()){
			int tmp=s.top();
			s.pop();
			sum[tmp]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
