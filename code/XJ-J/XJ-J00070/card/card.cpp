#include<iostream>
#include<cstdio>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vector<int> a(n),vis(m+1,0),ans(m+1,0),b;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(vis[a[j]]==0){
				b.push_back(a[j]);
				vis[a[j]]++;
			}
			else{
				while(b.back()!=a[j]){
					vis[b.back()]--;
					b.pop_back();
				}
			}
		}
		while(!b.empty()){
			ans[b.back()]++;
			vis[b.back()]--;
			b.pop_back();
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i];
		if(i!=m){
			cout << " ";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
