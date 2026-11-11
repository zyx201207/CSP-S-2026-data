#include<bits/stdc++.h>
using namespace std;
int n,m,a[300005];
string s,w;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		s+=(x+48);
	}
	for(int i=1;i<=n;i++){
		w=s;
		w.erase(0,i-1);
		for(int j=0;j<w.size();j++){
			if(w.find(w[j])<j)w.erase(0,j),j=0;
		}
		for(int j=0;j<w.size();j++)a[w[j]-48]++;
	}
	for(int i=1;i<=m;i++)cout<<a[i]<<" ";
	return 0;
}
