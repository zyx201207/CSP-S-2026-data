#include<bits/stdc++.h>
using namespace std;
bool v[10000001];
vector<int>t(10000001);
int ans[1000010];
int main(){ freopen("card.in","r",stdin);
	   freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int j=1;j<=n;j++){
	for(int i=j;i<=n;i++){
		if(v[a[i]]==1){
			int abc=0,t=1;
			while(t[k]!=a[i]){
				k++;
			}
			
			cnt=k;
		}
		else{
			t.push_back(a[i]);
			v[a[i]]=1;
			cnt++;
		}
	}
	for(int i=1;i<=cnt;i++){
		ans[t[i]]++;
	}
}
	for(int i=1;i<=m;i++)
cout<<ans[i]<<" ";
return 0;
}
