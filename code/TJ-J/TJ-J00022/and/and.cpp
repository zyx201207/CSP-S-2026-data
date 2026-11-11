#include<bits/stdc++.h>
using namespace std;
//int zhao[]={1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,ans=1;
	bool q=0;
	cin>>n>>m;
	vector<int> a(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(m==n){
			if(i==0) ans=a[i];
			ans=ans&a[i],q=1;	
		}
	}
	if(m==n-1){
		sort(a.begin(),a.end(),cmp);
		ans=a[0];
		for(int i=0;i<n-1;i++) ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	if(q){
		cout<<ans;
		return 0;
	}
	if(m==2){
		int maxx=0,maxn,maxm;
		sort(a.begin(),a.end(),cmp);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(max(maxx,a[i]&a[j])!=maxx&&a[i]!=a[j]) maxx=a[i]&a[j],maxn=i,maxm=j;
			}
		}
		cout<<maxx;
	}
	if(m==1){
		sort(a.begin(),a.end(),cmp);
		cout<<a[0];
		return 0;
	}
	
	return 0;
}
