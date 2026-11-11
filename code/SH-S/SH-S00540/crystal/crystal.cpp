#include<bits/stdc++.h>
using namespace std;
#define N 500005
typedef long long LL;
int n,m,ans;
LL a[N],s[N]; 
bool judge(int id,int mid){
	LL sum1=(id-mid)*a[id];
	LL sum2=s[id-1]-s[mid-1];
	return sum2+m>=sum1;
}
int count(int id){
	int l=1,r=id;
	while(l<=r){
		int mid=(l+r)/2;
		if(judge(id,mid)){
			r=mid-1;}
		else{
			l=mid+1;}
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,i-count(i)+1);
	}
	cout<<ans;
	return 0;
} 
