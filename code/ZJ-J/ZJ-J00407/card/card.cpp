#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int k[N];
int s[N];
int b[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		k[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		b[i]+=b[i-1];
		if(k[a[i]]!=i){
			b[i+1]-=b[i]+i;
			b[k[a[i]]]+=b[i]+i;
		}
	}
	for(int i=1;i<=n;i++)s[i]=i+b[i];
	for(int i=1;i<=m;i++)cout<<s[k[i]]<<" ";
	return 0;
} 
