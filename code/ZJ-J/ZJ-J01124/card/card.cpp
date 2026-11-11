#include <bits/stdc++.h>
using namespace std;
long long n,m,i,k,j,js[300010],a[500010],f[300010],px[300010],w[300010],rs;
queue <int> q,p;
void zhao(int x,int lp){
	int wz;
	wz=x;
	if(x>n) return ;
	if(w[a[wz]]!=wz) zhao(w[a[wz]],lp);
	else js[a[wz]]+=f[lp],zhao(wz+1,lp);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n==m){
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=1;i<=n;i++) f[a[i]]=i;
		for(i=1;i<=m;i++) cout<<f[i]<<" ";
		return 0;
	}
	if(n>500){
		for(i=1;i<=n;i++) cin>>a[i],f[a[i]]++,js[a[i]]=f[a[i]];
		for(i=n;i>=1;i--) if(!w[a[i]]) w[a[i]]=i,px[++rs]=a[i];
		for(i=1;i<=rs;i++) {
			zhao(w[px[i]]+1,px[i]);
		}
		for(i=1;i<=m;i++) cout<<js[i]<<" ";
		return 0;
	}
	for(i=1;i<=n;i++) cin>>a[i],f[a[i]]++;
	for(k=1;k<=n;k++){
		for(i=1;i<=m;i++) f[i]=0; 
		for(i=k;i<=n;i++){
			while(!q.empty()){
				if(q.front()==a[i]){
					q.pop();
					while(!q.empty()) q.pop();
				}
				else{
					p.push(q.front());
					q.pop();
				}
			}
			while(!p.empty()){
				q.push(p.front());
				p.pop();
			}
			q.push(a[i]);
			
		}
		while(!q.empty()){
			f[q.front()]=1;
			q.pop();
		}
		for(i=1;i<=m;i++)
			js[i]+=f[i];
	}
	for(i=1;i<=m;i++) cout<<js[i]<<" ";
	return 0;
}