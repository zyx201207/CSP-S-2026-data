#include<bits/stdc++.h>
using namespace std;
#define N 500005
int n,m;
int a[N];
int mp[N],ma=-1,mp7[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(mp,0,sizeof(mp));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			mp[a[j]]++;
		}
	}
	for(int i=1;i<=n;i++){
		mp7[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		if(mp[i]!=0){
			if(mp7[i]%2==0){
				cout<<mp[i]-1<<" ";
			}else{
				cout<<mp[i]<<" ";
			}
			
		}
	}
	return 0;
}

