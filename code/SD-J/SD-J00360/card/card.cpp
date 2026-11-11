#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int f=1,s=1;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i]-1){
			f==1;
			s++;
		}else{
			f==0;
			break;
		}
	}
	int ff=1;
	for(int i=2;i<=n;i++){
		if(a[i]>a[i]-1){
			ff==1;
			s++;
		}else{
			f==0;
			break;
		}
	}
	if(f==1){
		cout<<s;
		return 0;
	}
	if(ff==1){
		for(int i=1;i<=n;i++){
			cout<<i<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cout<<i<<" ";
	}
	return 0;
}
