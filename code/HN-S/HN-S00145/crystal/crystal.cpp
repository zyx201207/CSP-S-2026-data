#include<bits/stdc++.h>
using namespace std;
//哦，我真的爱你
//句句不轻易 
//气球在我手上
//rush b,flashboom
//bingobangoubangou,回家吃红烧鸡翅喽
//十月飘雪，削减白莲
 int n;
 long long m,res; 
 vector<long long> a;
 vector<long long> qian;
int max(int a,int b){
	return a>b?a:b;
}
int low(int r,int l,int i){
	if((i-r)*a[i]-(qian[i-1]-qian[r-1])<=m){
		return r;
	}else{
		int mid=(i+r)>>1;
		if((i-mid)*a[i]-(qian[i-1]-qian[mid-1])<=m&&(r+mid)>>1==r) return mid;
		if((i-mid)*a[i]-(qian[i-1]-qian[mid-1])>m&&(r+mid)>>1==r) return l;
		//cout<<(i-mid)*a[i]-(qian[i-1]-qian[mid-1])<<" "<<i<<"\n";
		if((i-mid)*a[i]-(qian[i-1]-qian[mid-1])>m){
			low(mid,l,i);
		}else{
			low(r,mid,i);
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a.resize(n+1);
	qian.resize(n+1);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	} 
	sort(a.begin()+1,a.end());
	qian[1]=a[1];
	qian[0]=0;
	for(int i=2;i<=n;i++){
		qian[i]=a[i]+qian[i-1];
		//cout<<qian[i]<<" ";
	}
	for(int i=2;i<=n;i++){
		long long k;
		k=m-i*a[i]+qian[i-1];
		int u=low(1,i,i);
	//	cout<<u<<" "<<i<<"\n";
		
	//	cout<<u<<" ";
		res=max(res,i-u+1);
	}
	cout<<res;
	return 0;
}
