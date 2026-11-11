#include<bits/stdc++.h>
using namespace std;
int v[100001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n);
	vector<int>cnt(m);
	vector<int>l(n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int j=1;
	while(j<=n){
	vector<int>c(n);
	for(int i=1;i<=n;i++){
		c[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		v[c[i]]=0;
	//	cout<<v[c[i]];
	}
	//cout<<endl;
	for(int i=j;i<=n;i++){
		if(v[c[i]]==0){
			v[c[i]]=1;
			l[c[i]]=i;
			continue;
		}else{
			for(int x=l[c[i]];x<=i-1;x++){
				v[c[x]]=0;
				c[x]=0;
			}
			v[c[i]]=1;
			continue;
		}
	}
	for(int i=j;i<=n;i++){
		if(v[c[i]]==1){
			cnt[c[i]]++;
		}
	//		cout<<c[i]<<" ";
	}
//	cout<<endl;
	j++;
}
for(int i=1;i<=m;i++){
	cout<<cnt[i]<<" ";
}
	return 0;
}
