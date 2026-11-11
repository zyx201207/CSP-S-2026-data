#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long energy[500002];
int l=0;
int r=0;
long long used=0;
void next(){
	used-=(energy[l]-energy[l+1])*(r-l);
	++l;
	for(int i=r+1;i<=n;++i){
		if(used+(energy[l]-energy[i])<=m){
			r=i;
			used+=(energy[l]-energy[i]);
		}else{
			break;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>energy[i];
	}
	sort(energy+1,energy+n+1,greater<long long>());
	energy[0]=energy[1];
	int maxx=1;
	for(int i=1;i<=n;++i){
		next();
		maxx=max(maxx,r-l+1);
	}
	cout<<maxx<<endl;
	return 0;
}
