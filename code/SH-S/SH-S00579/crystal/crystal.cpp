#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,r=1;
long long a[500005];
long long qzh[500005];
void search(int s,int t){
	if(t>=qzh[s+1]*ans){
		t=t-qzh[s+1]*ans;
		ans++;
	}
	else return;
	if(ans>r) r=ans;
	if(t>=0&&s+1<n){
		search(s+1,t);
	}
	return;
}
void paixu(){
	for(int i=1;i<n;i++){
		for(int j=1;j<=n-i;j++){
			if(a[j]>a[j+1]) swap(a[j],a[j+1]);
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	paixu();
	/*for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;*/
	a[0]=0;
	for(int i=1;i<=n;i++){
		qzh[i]=a[i]-a[i-1];
		//cout<<qzh[i]<<" ";
	}
	//cout<<endl;
	for(int i=1;i<=n;i++){
		ans=1;
		search(i,m);
	}
	cout<<r<<endl;
	return 0;
} 
