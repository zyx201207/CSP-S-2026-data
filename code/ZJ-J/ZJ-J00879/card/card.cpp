#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m;
long long a[N],w[M],s[M];
//a--记录出牌顺序 w--记录每种牌最后出现的位置 s--记录出现的次数 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		w[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){
			j=w[a[j]];
			s[a[j]]++;
			j++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
