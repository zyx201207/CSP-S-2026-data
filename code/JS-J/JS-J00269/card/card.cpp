#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	vector<int> b(n+1);
	vector<int> c(m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		for(int j=1;j<i;j++){
			if(a[i]==a[j])
				for(int k=a[j];k<=a[i-1];k++)
					a[k]=0;
		int ct=0;
		for(int j=1;j<=n;j++)	
			if(a[j]==i)ct++;
		c[i]=ct;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
