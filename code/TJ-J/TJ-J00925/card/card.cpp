#include<bits/stdc++.h>
using namespace std;
int a[500002];
int x[500002];
int b[300002];
int j=0;
int n,m;
void shan(int i){
	for(i;i<=n;i++){
		x[i]=0;
	}
}
bool check(int a){
	for(int i=1;i<=j;i++){
		if(x[i]==a){
			shan(i+1);
			j=i;
			return false;
		}
	}
	return true;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t=n;
	for(int k=1;k<=n;k++){
		memset(x,0,sizeof(x));
		j=0;
		
		for(int i=k;i<=n;i++){
			if(check(a[i])){
				x[++j]=a[i];
			}
		}
		for(int i=1;i<=j;i++){
			b[x[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
