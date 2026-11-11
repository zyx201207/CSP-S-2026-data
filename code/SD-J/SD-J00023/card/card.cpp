#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define ll long long
int a[N];
int cnt[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int o=1;o<=m;o++){
		stack<int>s;
		for(int i=o;i<=m;i++){
			bool f=1;
			for(int rt:s){
				if(rt==a[i])f=0;
			}
			if(f)s.push(a[i]);
			else{
				while(1){
					if(s.top()==a[i]){
						s.pop();
						break; 
					}
					s.pop();
				}
			}
		}
		for(int rt:s){
			if(rt<=n)cnt[rt]++;
		}
	}
	for(int i=1;i<=n;i++)cout<<cnt[i]<<' ';
	return 0;
}

