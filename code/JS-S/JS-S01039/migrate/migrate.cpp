#include<bits/stdc++.h>
using namespace std;
struct node{
	long long u,ans;
	//~ vector<int>v;
};
long long  c,t,n,d,x[5000003],ans,f[5000003],minn[5000003];
void bfs(int now){
	queue<node>q;
	q.push({now,0});
	while(!q.empty()){
		node u=q.front();
		q.pop();
		//~ long long l=u.u,r=n+1;
		//~ while(l+1<r){
			//~ long long mid=(l+r)>>1;
			//~ if(x[mid]-x[u.u]>d){
				//~ r=mid;
			//~ }
			//~ else l=mid;
		//~ }
		for(long long i=u.u+1;i<=n&&x[i]-x[u.u]<=d;i++){
			//~ vector<int>d=u.v;
			//~ d.push_back(i);
			if(minn[i]>u.ans+1){
				minn[i]=u.ans+1;
				f[i]=1;
				q.push({i,u.ans+1});
				//~ cout<<u.u<<" "<<i<<" "<<u.ans<<" "<<f[i]<<endl;
			}
			else if(minn[i]==u.ans+1){
				f[i]++;
				q.push({i,u.ans+1});
				//~ cout<<u.u<<" "<<i<<" "<<u.ans<<" "<<f[i]<<endl;
			}
			//~ for(long long j=1;j<=n;j++){
				//~ cout<<f[i]<<endl;
				//~ if(f[i]==2){
					//~ ans++;
				//~ }
			//~ }
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		for(long long i=1;i<=n;i++){
			bfs(i);
			for(long long j=1;j<=n;j++){
				//~ cout<<f[j]<<endl;
				if(f[j]==2){
					ans++;
				}
				f[j]=0;
				minn[j]=8e18;
			}
		}
		cout<<ans<<endl;
		//~ for(long long i=1;i<=n;i++){
			//~ l=i,r=n+1;
			//~ while(l+1<r){
				//~ long long mid=(l+r)>>1;
				//~ if(x[mid]-x[i]<2*d){
					//~ l=mid;
				//~ }
				//~ else r=mid;
			//~ }
			//~ _r=l;
			//~ cout<<"_l,_r:"<<_l<<" "<<_r<<" "<<x[i]<<" "<<x[_r]-x[i]<<endl;
			//~ if(_r<_l){
				//~ continue;
			//~ }
			//~ for(long long j=_l;j<=_r;j++){
				//~ long long __l,__r;
				//~ l=i,r=j+1;
				//~ while(l+1<r){
					//~ long long mid=(l+r)>>1;
					//~ if(x[mid]-x[i]>d){
						//~ r=mid;
					//~ }
					//~ else l=mid;
				//~ }
				//~ __r=l;
				//~ l=i,r=j+1;
				//~ while(l+1<r){
					//~ long long mid=(l+r)>>1;
					//~ if(x[j]-x[mid]>d){
						//~ l=mid;
					//~ }
					//~ else r=mid;
				//~ }
				//~ __l=r;
				//~ cout<<"__l,__r:"<<__l<<" "<<__r<<endl;
				//~ if(__r<__l||__r-__l+1>2||__r-__l+1<2){
					//~ continue;
				//~ }
				//~ else{
					//~ ans++;
				//~ }
			//~ }
		//~ }
		//~ cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
