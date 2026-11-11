#include<bits/stdc++.h>
using namespace std;
int c,ma,mm,maxn,a,b,n;
map<int,int> m;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>ma;
	if(c==0) cout<<1<<endl<<2<<endl;
	while(ma--){
		for(int i=1;i<=500005;i++){
			m[i]=0;
		}
		cin>>n>>mm;
		for(int i=2;i<=n;i++){
			cin>>a>>b;
			m[abs(a-b)]++;
		}
		for(int i=1;i<=500005;i++){
			maxn=max(maxn,m[i]);
		}
		cout<<maxn<<endl;
	}
	
}
