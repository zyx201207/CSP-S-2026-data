#include<bits/stdc++.h>
using namespace std;
int n,m;
const int MAX=5E5+10;
int a[MAX],b[MAX],s[MAX];
void sea(int k,int r){
	for(int i=1;i<=r;i++){
		if(b[i]==k){
			for(int j=i+1;j<=n;j++){
				b[j]=0;
			}
			return;
		}
	}
	b[r+1]=k;
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
		int t=0;
		for(int j=1;j<=n;j++){
			b[j]=a[j];
			t++;
		}
		for(int j=i;j<=n;j++){
			sea(a[j],t);
		}
		for(int i=1;i<=m;i++){
			s[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<" ";
	return 0;
}
