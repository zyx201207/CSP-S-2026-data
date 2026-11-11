#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
const int N=1e6+1;
int a[N];
bool c=false;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				c=true;
			}
		}
	}
	if(c==false){
		for(int i=1;i<=m;i++){
			cout<<i<<" ";
		}
		return 0;
	}else{
		for(int i=1;i<=n;i++){
		cout<<i<<" ";
		
	}
	}
	
	return 0;
}
