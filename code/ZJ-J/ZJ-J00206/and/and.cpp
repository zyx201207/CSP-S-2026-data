#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
bool a[N][31];
long long m,n,ans=2147483647,b[N];
void f(long long k,int i){
	long long s=1;
	for(int j=0;j<=30;j++){
		long long l=k&s;
		a[i][j]=(l==s);
		s*=2;
	}
	return;
}
queue<int>q;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;i++){
		f(b[i],i);
	}
	for(int i=30;i>=0;i--){
		int k=0;
		for(int j=1;j<=n;j++){
			k+=a[j][i];
			if(a[j][i]){
				q.push(j);
			}
			if(k==m){
				while(q.size()){
					int l=q.front();
					q.pop();
					ans=ans&b[l];
				}
				cout<<ans;
				return 0;
			}
		}
		while(q.size()){
			q.pop();
		}
	}
	return 0;
}