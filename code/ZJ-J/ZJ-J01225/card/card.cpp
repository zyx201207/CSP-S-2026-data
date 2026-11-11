#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],v[300005],s[300005];

bool theA(){
	for(int i=2;i<=n;i++){
		if(a[i-1]>a[i])return false;
	}
	return true;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[a[i]]++;
	}
	if(m<=2){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[n]){
				s[1]++;
				s[2]++;
			}else s[a[n]]++;
		}
		cout<<s[1]<<" "<<s[2];
		return 0;
	}
	if(theA()){
		for(int i=1;i<=n;i++){
			if(a[i]>a[i-1])s[a[i]]=i;
		}
		for(int i=1;i<=m;i++)cout<<s[i]<<" ";
		return 0;
	}
	return 0;
} 
