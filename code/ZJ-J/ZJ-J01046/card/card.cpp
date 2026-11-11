#include<bits/stdc++.h>
using namespace std;
int n,a[100005],f[100005],z[100005];
long long m;
string s;
map<int,int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(q[a[j]]!=0){
				for(int k=q[a[j]];k<j;k++){
					q[a[k]]=0;
				}
			}
			q[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(q[j]!=0){
				z[j]++;
			}
		}
		q.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<z[i]<<" ";
	}
	return 0;
}
