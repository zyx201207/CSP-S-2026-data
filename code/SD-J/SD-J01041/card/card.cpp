#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],cnt[N],b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		cnt[a[i]]=cnt[a[i]]+i;
	} 
	for(int i=1;i<=n;i++){
		if(cnt[a[i]]!=-1){cout<<cnt[a[i]]<<" ";cnt[a[i]]=-1;}
	}
	return 0;
} 

