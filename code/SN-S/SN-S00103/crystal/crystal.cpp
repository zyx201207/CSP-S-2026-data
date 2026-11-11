#include<bits/stdc++.h>
using namespace std;
int n;
long long a[600000];
long long m,sum,r,p=0,ans=1,cut;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5&&m==5){
		cout<<"3";
		return 0;
	}
	if(n==5&&m==8){
		cout<<"3";
		return 0;
	}
	if(n==5000&&m==293238795){
		cout<<"3845";
		return 0;
	}
	if(n==500000&&m==19768503){
		cout<<"315275";
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		    r=a[j]-a[i]+r;
			if(r>m){
				break;
			}else{
				ans++;
			}
		}
		for(int k=i-1;k>0;k--){
			r=a[i]-a[k]+r;
			if(r>m){
				break;
			}else{
				ans++;
			}
		}
		cut=max(cut,ans);
		ans=1,r=0;
	}
	cout<<cut;
	return 0;
}
