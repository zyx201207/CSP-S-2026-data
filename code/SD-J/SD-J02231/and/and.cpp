#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=INT_MIN;
//string ejz(long long x){
//	string t1="",t="";
//	
//	while(x!=0){
//		long long p1=x%2;
//		if(p1==1){
//			t1+='1';
//		}
//		else{
//			t1+='0';
//		}
//		x/=2;
//	}
//	long long j=t1.size()-1;
//	for(long long i=0;i<t1.size();i++){
//		t[i]=t1[j];
//		j--;
//	}
//	return t;
//}
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1,cmp);
	if(m==n){
		for(int i=1;i<=n;i++){
			ans+=a[i]&ans;
		}
	}
	else if(m==1){
		ans=a[1];
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}
	cout<<ans;
	
	return 0;
}
