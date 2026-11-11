#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long d[500005];//差分数组 
long long s1[500005],s2[500005];//后缀和 
long long query_ans(int p,int l){
	if(p==l) return 0;
	int siz=l-p+1;
	return s2[p]-d[p]-(s1[p+1]-s1[l+1])-s2[l+1]-s1[l+1]*(l-p+1);
}
int query(int p){//求以水晶p为合成目标答案 
	int l=1,r=p;
	int mid=(l+r)/2;
	while(l<=r){
		if(query_ans(mid,p)>m) l=mid+1;
		else r=mid-1; 
		mid=(l+r)/2;
	}
	return p-mid+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) d[i]=a[i]-a[i-1];
	for(int i=n;i>=1;i--) s1[i]=s1[i+1]+d[i];
	for(int i=n;i>=1;i--) s2[i]=s2[i+1]+s1[i]; 
	int ansd=1;
	for(int i=n;i>=1;i--){//从后向前查找 
		ansd=max(ansd,query(i));
	}
	cout<<ansd-1;
	return 0;
}
