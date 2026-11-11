#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];int mm=0,nb,ans;
bool cmp(int xx,int yy){
	return xx>yy;
}
void o(int x,int sum,int cnt){
	if(cnt==m){
		ans=max(ans,sum);
		return ;
	}
	if(x>n){
		return ;
	}
	o(x+1,sum&a[x],cnt+1);
	o(x+1,sum,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mm=max(a[i],mm);
	}
	if(m==1){
		cout<<mm;
		return 0;
	}
	else if(m==n){
		nb=a[1];
		for(int i=2;i<=n;i++){
			nb=a[i]&nb;
		}
		cout<<nb;
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	else if(n<=20){
		o(1,pow(2,21)-1,0);
		cout<<ans;
		return 0;
	}
	else{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
		return 0;
	}
	return 0;
}
