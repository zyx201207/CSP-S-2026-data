#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+10;
const int inf = 2e9;

int n,m,a[N],v[N];
//vector<int> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		v[a[i]]++;
		if(!v[a[i]]&1){
			v[a[i]]--;
			int j = i+1;
			while(a[j]!=a[i]) v[a[i]]--;
			v[a[i]]--;
			for(int t=j+1;t<=n;t++) v[a[t]]++;
		}else for(int t=i+1;t<=n;t++) v[a[t]]++;
	}
	for(int i=1;i<=m;i++) cout<<v[i]<<" ";
	return 0;
} 
