#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
struct node{
	int ys;
	bool flag;
	string erjz;
}a[200005];
bool cmp(node x,node y){
	if(x.flag==y.flag)return x.ys>y.ys;
	return x.flag>y.flag;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i].ys;
		a[i].flag=1;
		int aiys=a[i].ys;
		while(aiys!=0){
			a[i].erjz=char(aiys%2+'0')+a[i].erjz;
			aiys/=2;
		}
		int sz=30-a[i].erjz.size();
		while(sz!=0){
			a[i].erjz='0'+a[i].erjz;
			sz--;
		}
	}
	sort(a,a+n,cmp);
	int r=n-1;
	for(int i=0;i<30;i++){
		int cnt=0;
		for(int j=0;j<=r;j++){
			if(!a[j].flag){
				r=j-1;
				break;
			}
			if(a[j].erjz[i]=='1')cnt++;
		}
		if(cnt>=m){
			int anss=1;
			for(int j=2;j<=30-i;j++)anss*=2;
			ans+=anss;
			for(int j=0;j<=r;j++)if(a[j].erjz[i]!='1')a[j].flag=0;
			sort(a,a+r,cmp);
		}
	}
	cout<<ans;
	return 0;
}
//TLE
