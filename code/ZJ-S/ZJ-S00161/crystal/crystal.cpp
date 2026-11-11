#include<bits/stdc++.h>
using namespace std;
int n;
long long m,ans=0,p;
int a[50];
int turn(int x){
	long long num=m,cnt=0;
	long long q[50];
	for(int k=1;k<=n;k++){
		q[k]=abs(x-a[k]);
	}
	sort(q+1,q+n+1);
	for(int i=1;i<=n;i++){
		if(num<q[i])return cnt;
		num-=q[i];
		cnt++;
	}
	return cnt;
}
bool check1(){
	if(abs(a[1]-a[2])==1)return 1;
	return 0;
}
bool check2(){
	if(abs(a[1]-a[2])==abs(a[2]-a[3])){
		p=abs(a[1]-a[2]);
		return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		 cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=16){
		for(int i=1;i<=n;i++){
			long long v=turn(i);
			ans=max(ans,v);
		}
		cout<<ans<<"\n";
	}else if(check1()){
		ans=1;
		long long cnt=1;
		while(m>0&&ans<=n){
			m-=cnt;
			cnt+=ans/2;
			ans+=1;
		}
		cout<<ans<<"\n";
	}else if(check2()){
		ans=1;
		long long cnt=p;
		while(m>0&&ans<=n){
			m-=cnt;
			cnt+=ans/2*p;
			ans+=1;
		}
		cout<<ans<<"\n";
	}else{
		cout<<n;		
	}
	
	return 0;
}
