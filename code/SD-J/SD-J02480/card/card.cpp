#include<bits/stdc++.h> 
using namespace std;
int n,m,a[500010];
int find(int x){
	int cnt=0;
	for(int i=1;i<=n;i++){
		bool f=false;
		for(int j=i;j<=n;j++){
			if(a[j]==x){
				f=true;
			}
		}
		if(f==true){
			cnt++;
		}
	}
	return cnt;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<find(i)<<" ";
	}
	return 0;
}
