#include<bits/stdc++.h> 
using namespace std;
long long n,m,t=1,o,p;
long long a[500005],m2[300005];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(t!=n){
		o=100007;
		p=0;
		for(long long q=1;q<=m;q++){
		for(long long i=t;i<=n;i++){
			for(long long j=n;j>=t+1;j--){
				if(a[i]==q && a[j]==q){
				o=min(i,o);
				p=max(j,p);
				break;
			}
		}
	}	
		}
		
	for(int i=t;i<=o;i++){
		m2[a[i]]++;
	}
	for(int i=p;i<=n;i++){
		m2[a[i]]++;
	}
	t++;
	}
	for(int i=1;i<=m;i++){
		cout<<m2[i]<<" ";
	}
}
