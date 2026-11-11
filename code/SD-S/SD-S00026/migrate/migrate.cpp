#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long shu[1000500];
int l[1000500],r[1000500],c,q,lcan[1000500],rcan[1000500];
long long ans = 0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>q;
	while(q--){
	
	
	cin>>n>>m;
	ans = 0;
	for(int i = 1;i<=n+20;i++){
		shu[i] = 0;
		l[i] = 0;
		r[i] = 0;
		lcan[i] = 0;
		rcan[i] = 0;
	}
	for(int i = 1;i<=n;i++){
		cin>>shu[i];
	}
	lcan[1] = 0;
	for(int i = 2;i<=n;i++){
		if(shu[i]-shu[i-1]<=m){
			lcan[i] = lcan[i-1]+1;
		}else{
			lcan[i] = 0;
		}
	}
	rcan[n] = 0;
	for(int i = n-1;i>=1;i--){
		if(shu[i+1]-shu[i]<=m){
			rcan[i] = rcan[i+1]+1;
		}else{
			rcan[i] = 0;
		}
	}
	int len = 0;
	for(int i = 1;i<=n;i++){
		if(shu[i+2]-shu[i]<=m&&shu[i+3]-shu[i+1]<=m&&shu[i+3]-shu[i]>m){
			len++;
			l[len] = i;
			r[len] = i+3;
		}
	}
//	cout<<len<<endl;
//	cout<<l[1]<<' '<<r[1];
//	cout<<endl<<l[2]<<' '<<r[2]<<endl;
	if(len==0){
		cout<<0<<endl;
		continue;
	}
	if(len==1){
		cout<<(1+lcan[l[1]])*(1+rcan[r[1]])<<endl;
		continue;
	}
	for(int i = 1;i<=len;i++){
		long long zuo = 0,you = 0;
		if(i==1){
			zuo=lcan[l[1]];
			if(l[2]>=r[1]){
				you=min(rcan[r[1]],l[2]-r[1]);
			}else{
				you=min(rcan[r[1]],r[2]-r[1]-1);
			}
			ans+=(zuo+1)*(you+1);
		}else if(i==len){
			you=rcan[r[len]];
			if(l[len]>=r[len-1]){
				you=min(lcan[l[len]],l[len]-r[len-1]);
			}else{
				you=min(lcan[l[len]],l[len]-l[len-1]-1);
			}
			ans+=(zuo+1)*(you+1);
		}else{
			
			if(l[i]>=r[i-1]){
				zuo=min(lcan[l[i]],l[i]-r[i-1]);
			}else{
				zuo = min(lcan[l[i]],l[i]-l[i-1]-1);
			}
			if(r[i]<=l[i+1]){
				you=min(rcan[r[i]],l[i+1]-r[i]);
			}else{
				you=min(rcan[r[i]],r[i+1]-r[i]-1);
			}
			ans+=(zuo+1)*(you+1);
		}
	}
	cout<<ans<<endl;
	
	
	
	}
	return 0;
}

