#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],b[100005],maxn=-1e9; 
int f(int t,int t1){
	for(int i=t;i>=1;i--){
		if(a[i]<t1&&m-(t1-a[i])>=0){
			m=m-(t1-a[i]);
			a[i]=t1;
		}
		else{
			return 0;
		}
	}
}
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		f(i,a[i+1]);
	}
	int y=0;
	for(int i=1;i<=n;i++){
		b[a[i]]++;
		y=max(a[i],y);
	}
	for(int i=1;i<=y;i++){
		maxn=max(b[i],maxn);
	}
	cout<<maxn;
	return 0;
} 
