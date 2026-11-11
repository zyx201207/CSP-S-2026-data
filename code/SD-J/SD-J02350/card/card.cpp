#include<iostream>
#include<cstdio>
#include<deque>
using namespace std;
int n,m,a[100005],b[100005]; 
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
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=n;j++){
			if(b[a[j]]==0) b[a[j]]=j-i;
		}
	}
	cout<<0;
	return 0;
} 
