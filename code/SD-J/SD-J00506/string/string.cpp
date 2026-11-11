#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans;
struct st{
	ll data;
	char s;
}f[200050];
int main(){
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>f[i].data>>f[i].s;
	}
	for(int i=1,j=n;i<j;){
		if(f[i].s==f[j].s){
			if(f[i].data>f[j].data){
				f[i].data-=f[j].data;
				j--;
			}
			else if(f[j].data>f[i].data){
				f[j].data-=f[i].data;
				i++;
			}
			else{
				i++;
				j--;
			}
		}
		else{
			if(f[i].data>f[j].data){
				f[i].data-=f[j].data;
				ans+=f[j].data;
				j--;
			}
			else if(f[j].data>f[i].data){
				f[j].data-=f[i].data;
				ans+=f[i].data;
				i++;
			}
			else{
				ans+=f[j].data;
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
