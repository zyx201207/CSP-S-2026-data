#include<bits/stdc++.h>
using namespace std;
const long long MAXN=5e5+5;
long long n,m;
long long a[MAXN];
long long last;
long long front;
bool flag[MAXN];
long long p[MAXN];
long long ans[MAXN];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		memset(flag,0,sizeof(flag));
		memset(p,0,sizeof(p));
		last=front=-1;
		for(long long j=i;j<=n;j++){
			if(!flag[a[j]]||(p[a[j]]>=last&&p[a[j]]<=front&&last!=-1)){
				p[a[j]]=j;
				flag[a[j]]=true;
			}
			else{
				last=p[a[j]];
				//cout<<"last:"<<p[a[j]]<<"~"<<j<<endl;
				p[a[j]]=j;
				front=p[a[j]]-1;
			}
		}
		for(long long j=1;j<=m;j++){
			if(p[j]>last&&p[j]!=0){
				ans[j]+=1;
				//cout<<i<<" "<<j<<" "<<p[j]<<endl; 
			}
		}
	}
	for(long long j=1;j<=m;j++){
		cout<<ans[j]<<" ";
	}
	return 0;
}
