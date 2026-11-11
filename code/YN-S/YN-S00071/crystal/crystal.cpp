#include<bits/stdc++.h>
#define AC return 0
#define ll long long 
#define vec vector
using namespace std;
const long N=5e5+15;
ll n,m,adds=0;
vec<long> s[N];
long as[N];
long fa[N];
bool compare(long a,long b){
	return a<b;
}
int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long i=1;i<=n;i++){
		//long u;
		//cin>>u;
		cin>>as[i];
	}
	sort(as,as+n,compare);
	for(long long i=1;i<=n;i++){
		long  cha=as[i+1]-as[i];
		if(cha*i<=m){
			m-=cha*i;
			//cout<<'m'<<m<<" "<<"adds"<<adds<<endl;
			}
		else{break;}
		adds=i+1;
		}
	cout<<adds<<endl;	
	AC;
}
