#include<bits/stdc++.h>
using namespace std;
int a[500010],t[300010],t2[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(t[a[i]]){
			for(int j=t[a[i]];j<i;j++){
				t[a[j]]=0;
			} 
		}
		t[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		if(t[i]!=0) t2[i]++;
	}
	int x=n-1;
	while(x--){
		memset(t,0,sizeof(t));
		for(int i=n-x;i<=n;i++){
			if(t[a[i]]){
				for(int j=t[a[i]];j<i;j++){
					t[a[j]]=0;
				} 
			}
			t[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			if(t[i]!=0) t2[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t2[i]<<" "; 
	} 
	return 0;
}
