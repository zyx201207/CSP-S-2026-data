#include<bits/stdc++.h>
using namespace std;
#define int long long
int an[500001],maxn=INT_MIN;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,f=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>an[i];
		if(i>2&&an[i]-an[i-1]!=an[i-1]-an[i-2]) f=1;
	}
	sort(an+1,an+n+1);
	if(!f){
		int x=an[2]-an[1];
		int k=0,s=0;
		for(int i=1;i<n;i++){
			if(k>m) break;
			k+=i*x;
			s++;
		}
		cout<<s;
	}
	else{
		for(int i=2;i<=n;i++){
			int k=0,s=1;
			for(int j=i-1;j>=1;j--){
				k+=an[i]-an[j];
				if(k>m) break;
				s++;
				maxn=max(maxn,s);
			}
		}
		cout<<maxn;
	}
	return 0;
}
