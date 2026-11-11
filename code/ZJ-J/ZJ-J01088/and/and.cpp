#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,i,j,p,ma,sw,ssw,sum;
int a[210000],b[32];
void dfs(int x,int mm,int p){
	if(x==n+1){
		if(mm==m) ma=max(ma,p);
		return;
	}
	if(mm+n-x+1<m) return;
	if(mm==m&&p<ma) return;
	if(mm+1<=m) dfs(x+1,mm+1,p&a[x]);
	dfs(x+1,mm,p);
}
bool check(){
	int i;
	for(i=1;i<=n;i++){
		p=a[i]+1;
		while(p>0){
			if(p%2) return 0;
			p/=2;
		}
	}
	return 1;
}
bool pd(){
	int i;
	for(i=1;i<=n;i++){
		if(a[i]!=i-1) return 0;
	}
	return 1;
}
bool ok(){
	int i;
	for(i=1;i<=n;i++){
		if(a[i]>=4) return 0;
	}
	return 1;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n;i++) cin>>a[i];
    if(n<=20){
    	p=1;
    	for(i=1;i<=21;i++) p*=2;
   		p--;
    	dfs(1,0,p);
    	cout<<ma;
	}
	else if(n<=2000){
		if(m==1){
			sort(a+1,a+n+1);
			cout<<a[n];
		}
		else if(m==n){
			p=a[1];
			for(i=2;i<=n;i++) p=p&a[i];
			cout<<p;
		}
		else{
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					if(i!=j) ma=max(ma,a[i]&a[j]);
				}
			}
			cout<<ma;
		}
	}
	else{
		if(m==n-1){
			for(i=1;i<=n;i++){
				p=a[i];
				sw=0;
				while(p>0){
					sw++;
					b[sw]+=p%2;
					p/=2;
				}
			}
			for(i=1;i<=n;i++){
				p=a[i];
				ssw=0;
				while(p>0){
					ssw++;
					b[ssw]-=p%2;
					p/=2;
				}
				p=1;
				sum=0;
				for(j=1;j<=sw;j++){
					if(b[j]==n-1) sum+=p;
					p*=2;
				}
				ma=max(ma,sum);
				p=a[i];
				ssw=0;
				while(p>0){
					ssw++;
					b[ssw]+=p%2;
					p/=2;
				}
			}
			cout<<ma;
		}
		else if(check()){
			sort(a+1,a+n+1);
			cout<<a[n-m+1];
		}
		else if(pd()){
			p=1;
    		for(i=1;i<=21;i++) p*=2;
   			p--;
			for(i=n;i>=n-m+1;i--) p=p&a[i];
			cout<<p;
		}
		else if(ok()){
			for(i=1;i<=n;i++){
				if(a[i]==3) sum++;
			}
			if(sum>=m){
				cout<<3;
				return 0;
			}
			for(i=1;i<=n;i++){
				if(a[i]==2) sum++;
			}
			if(sum>=m){
				cout<<2;
				return 0;
			}
			for(i=1;i<=n;i++){
				if(a[i]==2) sum--;
			}
			for(i=1;i<=n;i++){
				if(a[i]==1) sum++;
			}
			if(sum>=m) cout<<1;
			else cout<<0;
		}
		else{
			sort(a+1,a+n+1);
			p=a[n];
			while(p>0){
				sw++;
				b[sw]+=p%2;
				p/=2;
			}
			p=1;
			for(i=1;i<=sw-1;i++) p*=2;
			cout<<p-1;
		}
	}
}