#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int a[N];
ll ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(m==1){
		ans[1]=n;
	}else if(m==2){
		ans[a[n]]=n;
		
	}else{
		for(int i=1;i<=n;++i){
			++ans[a[i]];
		}
		for(int i=2;i<=m;++i){
			ans[i]+=ans[i-1];
		}
	}
	for(int i=1;i<=m;++i){
		if(i!=1)cout<<' ';
		cout<<ans[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
