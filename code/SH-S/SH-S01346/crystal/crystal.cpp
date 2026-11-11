#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,crystals[500005],answer=-1e9;
int maxs=-1e9,mins=1e9,num;
bool check(int mid){
	int subtract=crystals[2]-crystals[1];
	int sum=0;
	for(int i=0;i<mid;i++){
		sum+=i*subtract;
	}
	return sum<=m;
}
//bool check2(int mid){
//	return crystals[mid]<=
//}
void trickpoint1(){
	int l=1,r=n,mid,ans;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;l=mid+1;
		}else r=mid-1;
	}
	cout<<ans;
}
void trickpoint2(){
	int l=1,r=n,mid,ans;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;l=mid+1;
		}else r=mid-1;
	}
	cout<<ans;
}
void solve(int x){
	//找最后个小于的 
	int ms=m;
	int l=1,r=n,mid,ans;
	while(l<=r){
		mid=(l+r)/2;
		if(crystals[mid]<=x){
			ans=mid;l=mid+1;
		}else r=mid-1;
	} 
	//cout<<ans<<" ";
	int sum=0;
	for(int i=ans;i>=1;i--){
		ms-=(x-crystals[i]);
		if(ms>=0){
			sum++;
		}else break;
	}
	answer=max(answer,sum);
	//cout<<answer;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool ok=1,ok2=1;
	for(int i=1;i<=n;i++){
		cin>>crystals[i];
		if(crystals[i]!=i) ok=0;
		if(i==2)num=crystals[i]-crystals[i-1];
		maxs=max(maxs,crystals[i]);
		mins=min(mins,crystals[i]);
		if(i<2) continue;
		if(crystals[i]-crystals[i-1]!=num) ok2=0;
	} 
	if(ok){
		trickpoint1();//crystal[i]=i 
	}else if(ok2){
		trickpoint2();//等差数列 
	}else{
		sort(crystals+1,crystals+n+1);
		for(int i=mins;i<=maxs;i++){
			//cout<<i<<": ";
			solve(i);
			//cout<<endl;
		}
		cout<<answer;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
