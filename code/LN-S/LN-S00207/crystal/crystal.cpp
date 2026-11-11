#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL n,m,ans;
vector<LL> a;
vector<LL> zjt,p;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>n>>m;
	
	a.resize(n);
	zjt.resize(n);
	p.resize(n);
	for(LL i=0,ip;i<=n-1;i++){
		cin>>ip;
		a[i]=ip;
	}
	
	sort(a.begin(),a.end());
	
	for(LL i=1;i<=n-1;i++){
		zjt[i]=a[i]-a[i-1];
	}
	
	for(LL i=1;i<=n-1;i++){
		zjt[i]*=i;
	}
	
	//////
	/*
	for(auto it:zjt){
		cout<<it<<" ";
	}
	*/
	ans=1;
	
	for(LL i=1;i<=n-1;i++){
		p[i]=p[i-1]+zjt[i];
		if(p[i]>m){
			break;
		}
		ans++;
	}
	/*
	for(auto it:p){
		cout<<it<<" ";
	}
	*/
	
	
	
	cout<<ans;
	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}










/*
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>n>>m;
	
	a.resize(n);
	
	for(LL i=0,ip;i<=n-1;i++){
		cin>>ip;
		a[i]=ip;
	}
	
	sort(a.begin(),a.end());
	
	LL tmp=0,ick=0;
	for(LL i=0;i<=n-2;i++){
///		cout<<"i"<<i;/////////////
		tmp=a[i+1]-a[i];
		ick+=tmp*(i+1);
		ans++;
///		cout<<" ick"<<ick<<endl;////////////
		
		if(ick>m){
			ick-=tmp*(i+1);
			///ans--;
			break;
		}
	}
		
	
	cout<<ans;
	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
*/
