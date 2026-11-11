#include<bits/stdc++.h>
using namespace std;
int n,m;
int sl[200010];
int maxn=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int a=1;a<=n;++a){
		cin>>sl[a];
	}
	if(m==1){
		for(int a=1;a<=n;++a){
			maxn=max(maxn,sl[a]);
		}
	}else if(m==2){
		for(int a=1;a<=n;++a){
			for(int b=a+1;b<=n;++b){
				maxn=max(maxn,sl[a]&sl[b]);
			}
		}
	}
	cout<<maxn;
	return 0;
}
/*
4 2
3 15 12 12
*/
