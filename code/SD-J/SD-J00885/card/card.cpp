#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n,m;
int a[N],t[N];
bool ggg = 0;
void jjj(){
	bool gggg = 0;
	for(int i=1;i<=n;i++){
		if(a[i]<a[i-1]){
			gggg = 1;
		}
	}
	if(gggg = 0) ggg = 1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n == 1){
		for(int i=1;i<=a[1]-1;i++){
			cout<<0<<" ";
		}
		cout<<1;
		return 0;
	}
	if(m == 1){
		long long cnt = 0;
		for(int i=1;i<=n;i++){
			cnt+=(n%2);
		}
		for(int i=1;i<=a[1];i++){
			cout<<0<<" ";
		}
		cout<<cnt;
	}
	
	jjj();
	if(ggg = 1){
		for(int j=1;j<=n;j++){
			for(int i=j;i<=n;i++){
				if(a[i]!=a[i+1]){
					t[a[i]]++;
				}else{
					i++;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<t[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		cout<<0<<" ";
	}
	return 0;
}
