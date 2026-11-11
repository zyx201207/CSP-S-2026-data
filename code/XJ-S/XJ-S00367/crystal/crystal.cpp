#include<bits/stdc++.h>
using namespace std;
const long long unsigned Num=1e15+5;
long long n,m,a[Num],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;m>0;i++){
		if(m<i) break;
		m-=i;
		ans+=1;
	}if(ans>n){
		cout<<n;
		return 0;
	}cout<<ans;
	return 0;
} 
