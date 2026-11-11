#include<bits/stdc++.h>
using namespace std;
multiset<int>s;
int n,m;
int a[200005],st,t[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[n-i+1];
		if(s.find(st)!=s.end()){
			for(int j=n;j>=1;j--){
				if(a[j]==st)break;
				a[j]=0;
			}
		}
		else s.insert(st);
		for(int j=1;j<=n;j++){
			t[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
//expected 35pts       2/5
