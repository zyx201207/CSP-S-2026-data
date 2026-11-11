#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int u[N],a[N],s[N];
void check(int x){
	memset(u,0,m+1);
	for(int i=x;i<=n;i++){
		if(u[a[i]]==0){
			u[a[i]]=i;
		}
		else{
			for(int j=u[a[i]]+1;j<=i;j++){
				u[a[j]]=0;
			}
			u[a[i]]=i;
		}
	}
	for(int i=x;i<=n;i++){
		if(u[a[i]]){
			s[a[i]]++;
			u[a[i]]=0;
		}
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		check(i);
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}

