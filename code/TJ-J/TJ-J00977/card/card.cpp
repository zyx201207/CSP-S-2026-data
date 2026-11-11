#include<bits/stdc++.h>
using namespace std;
//priority_queue<int>a;
//vector<int>s;
const int N=5e5+5;
int n,m;
map<int,int>a;
int d[N];
map<int,int>b;
int s[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(!a[s[i]])a[s[i]]=i;
		else b[a[s[i]]]=i,a[s[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[j])j=b[j]-1;
			else d[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
