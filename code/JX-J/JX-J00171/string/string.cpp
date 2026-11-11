#include<bits/stdc++.h>
using namespace std;
struct d{
	int a;
	char c;
}ds[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ds[i].a>>ds[i].c;
	}
	for(int i=1;i<=(n+1)/2;i++){
		if(ds[i].c!=ds[n+1-i].c){
			ans=ans+min(ds[i].a,ds[n+1-i].a);

		}
		if(ds[i].a>ds[n+1-i].a){
			if(ds[n-i].c!=ds[i].c){			
				ans+=ds[i].a-ds[n+1-i].a;
			}
			ds[n-i].a-=ds[i].a-ds[n+1-i].a;
		}
		else{
			if(ds[i+1].c!=ds[n-i+1].c){
				ans+=ds[n+1-i].a-ds[i].a;
				}
				ds[i+1].a-=ds[n+1-i].a-ds[i].a;				
			}
	}
	cout<<ans;
	return 0;
	}
