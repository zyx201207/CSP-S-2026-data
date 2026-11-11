#include <bits/stdc++.h>
using namespace std;
const int MX=1e6+10;
long long n,m;
long long a[MX],pos[MX],s[MX];
bool visit[MX];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool f=true;
	memset(visit,false,sizeof(visit));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pos[a[i]]=i;
		if(a[i]<a[i-1]) f=false;
	}
	if(f){
		for(int i=1;i<m;i++){
			cout<<pos[i]<<" "; 
		}
		cout<<n;
		return 0;
	}
	cout<<n;
	return 0;
}
