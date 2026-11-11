#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int a[N+10],b[N+10],f[N+10];

int n,m;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		deque<int> dp;
		for(int j=1;j<=n;j++) f[j]=false;
		for(int j=i;j<=n;j++){
			if(!f[a[j]]){
				f[a[j]]=true;
				dp.push_back(a[j]);
			}else if(f[a[j]]){
				while(!dp.empty()&&dp.back()!=a[j]){
					dp.pop_back();
//					cout<<1;
				}
			}
			
		}
		while(!dp.empty()){
			
			b[dp.back()]++;
			dp.pop_back();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
