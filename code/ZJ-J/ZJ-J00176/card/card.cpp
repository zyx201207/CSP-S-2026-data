#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5,M=5e5+5;;
int T[N];
int a[M];
int cnt[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stack<int> v;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			T[a[j]]++;
			v.push(a[j]);
			if(T[a[j]]==2){
				T[a[j]]--;
				v.pop();
				while(v.top()!=a[j]){
				T[v.top()]--;
				v.pop();
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(T[i]!=0)cnt[i]++;
		}
		memset(T,0,sizeof(T));
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}