#include<bits/stdc++.h>
using namespace std;
//vector<int> v[200007];
long long n,a[40][200007],cnt,m,wei,need[200007],ne,ans,qq=1;
struct T{
	int t0,t1;
}t[40];
int mi2(long long x){
	for(int i=1;i<=x;i++){
		qq*=2;
	}return qq;
}
void find2(long long ax,long long x){
//	v[x].push_back(ax-ax/2);
	cnt++;
	a[cnt][x]=ax%2;
	ax/=2;
	if(ax>0)
		find2(ax,x);
}int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ne=n;
	for(int j=1;j<=35;j++){
		for(int i=1;i<=n;i++)
			a[j][i]=-1;
	}for(int i=1;i<=n;i++){
		long long aa;
		cin>>aa;
		find2(aa,i);
		cnt=0;
	}for(int i=35;i>=1;i--){
		for(int j=1;j<=n;j++){
			if(a[i][j]==1)
				t[i].t1++;
			if(a[i][j]==0)
				t[i].t0++;
//			cout<<a[i][j]<<" ";
		}if((t[i].t0>=m||t[i].t1>=m)&&wei==0)
			wei=i;
	}for(int i=wei;i>=1;i--){
	//t[i].t0<=t[i].t1&&
		if(t[i].t1>=m){
			for(int j=1;j<=n;j++){
				if(a[i][j]!=1&&need[j]==0&&ne>m){
					need[j]=1;
					ne--;
				}
			}
		}
//		else if(t[i].t0>t[i].t1&&t[i].t0>=m){
//			for(int j=1;j<=n;j++){
//				if(a[i][j]!=0&&need[j]==0&&ne>m){
//					need[j]=1;
//					ne--;
//				}
//			}
//		}
//		if(t[i].t0>=m||t[i].t1>=m)
//			ans[i]=1;
//		cout<<t[i].t0<<" "<<t[i].t1<<" "<<wei<<'\n';
	}
//	for(int i=1;i<=wei;i++){
//		for(int j=1;j<=n;j++){
//			cout<<a[i][j]<<" ";	
//		}cout<<endl;
//	}
	for(int i=wei;i>=1;i--){
		t[i].t1=0;
		t[i].t0=0;	
		//cout<<t[i].t0<<" "<<t[i].t1<<" "<<'\n';
		for(int j=1;j<=n;j++){
			if(need[j]==0){
				if(a[i][j]==1)
					t[i].t1++;
				if(a[i][j]==0)
					t[i].t0++;	
			}
//			cout<<a[i][j]<<" ";
		}
	//	cout<<t[i].t0<<" "<<t[i].t1<<" "<<'\n';
		if(t[i].t1>=m){
			qq=1;
			ans+=mi2(i-1);
//			cout<<i<<" "<<qq<<" "<<endl;
		}
	}cout<<ans;
//	for(int j=1;j<=n;j++){
//		cout<<need[j];
//	}
//	for(int i=1;i<=wei;i++){
//		cout<<ans[i]<<" ";
//	}
}
