#include<bits/stdc++.h> 
using namespace std;
long long n,m,ans;
long long a[200005];
long long now;
long long hd=1;
long long ha[1>>20];
void an(int q,int sum){
	if(sum==m){
		if(ans<now)ans=now;
		return;
	}else if(sum+n-q<m)return;
	int t=0;
	 if(ha[a[q]]==2){
	 	t=1;
	 }
	int x=now;
	for(int i=q+1+t;i<=hd;i++){
		now&=a[i];
		an(i,sum+1);
		now=x;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int j;
		cin>>j;
		if(ha[j]==0||ha[j]==1){
			a[hd]=j;
			ha[j]++;
			hd++;
		}
	}
	for(int i=1;i<=hd;i++){
		now=a[i];
		an(i,1);
	}cout<<ans;
	return 0;
}
