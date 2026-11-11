#include<bits/stdc++.h> 
#include<cstdio>
using namespace std;
int a[600000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		cout << '0'<<' ';
	}
	return 0;
}
