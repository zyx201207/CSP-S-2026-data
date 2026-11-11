#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,s=1,w=1,ans=0; 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(;w<=n;w++){
		if(w>s){
			if((a[w]-a[w-1])*(w-s)<=m){
				m-=(a[w]-a[w-1])*(w-s);
			}
			else{
				m+=a[w-1]-a[s];
				s++;
				w--;
			}
		} 
		ans=max(ans,w-s+1);
	}
	cout<<ans;
	return 0;
} 
