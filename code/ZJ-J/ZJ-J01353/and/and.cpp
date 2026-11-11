#include<bits/stdc++.h>
using namespace std;
long long ans=INT_MIN,n,m,a[208888];
void dfs(long long step,long long g,long long y){
	cout<<step<<' '<<g<<' '<<y<<' '<<ans<<endl;
	if(g>=m){
		ans=max(ans,y);
		return ;
	}
	for(int i=step;i<=n;i++){
		long long q,w,y,e,p;
		q=a[i];
		w=y;
		e=0;
		p=0;
		if(g==0){
			p=a[i];
		}
		else{
			while(q!=0&&w!=0){
			if(q%2==w%2){
				p+=pow(2,e)*(q%2);
			}
			w=w/2;
			q=q/2;
			e++;
		    }
		}
		if(p<=ans){
			continue;
		}
		else{
			g++;
			dfs(i+1,g,p);
			g--;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	long long z=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		z=max(z,a[i]);
	}
	if(m==1){
		cout<<z;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i!=j){
					long long q=a[i],w=a[j],p=0,e=0;
					while(q!=0&&w!=0){
			            if(q%2==w%2){
				        p+=pow(2,e)*(q%2);
			            }
			            w=w/2;
			            q=q/2;
			            e++;
		            }
		            ans=max(ans,p);
				}
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==n){
		long long p=a[1],w,e=0,q;
		for(int i=2;i<=n;i++){
			w=a[i];q=p;p=0;e=0;
			while(q!=0&&w!=0){
		        if(q%2==w%2){
				p+=pow(2,e)*(q%2);
			}
			w=w/2;
			q=q/2;
			e++;
		    }
		}
		cout<<p<<endl;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}/*
4 2
3 15 12 12
5 3
31 3 1 15 7
*/
