#include<bits/stdc++.h>
using namespace std;

int cnt,n,m,f,a[200010],vis[300010];
int s[200010];

int find(int x){
	for(int i = cnt;i>=1;i--){
		if(x==s[i]){
			f=i;
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		cnt=0;
		for(int j = i;j<=n;j++){
			f=0;
			if(find(a[j])){
				cnt++;
				s[cnt]=a[j];
			}else{
				cnt=f-1;
				cnt++;
				s[cnt]=a[j];
			}
		}
		for(int i = 1;i<=cnt;i++){
			vis[s[i]]++;
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<vis[i]<<" ";
	}
	return 0;
}