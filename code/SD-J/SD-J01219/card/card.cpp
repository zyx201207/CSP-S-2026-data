#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
long long n,m,a[N],fa[N],s[M],sum[M];
bool f[M];
void find(int id){
	int k=id;
	while(k!=0){
		sum[k]+=s[id];
		k=fa[k];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[a[i]]++;
	}
	for(int i=n;i>=1;i--){
		if(!f[a[i]]){
			f[a[i]]=true;
			if(i==n){
				fa[a[i]]=0;
			}else{
				fa[a[i]]=a[i+1];
			}
		}
	}
	for(int i=1;i<=m;i++) find(i);
	for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=m;i++) cout<<fa[i]<<" ";
	return 0;
} 
