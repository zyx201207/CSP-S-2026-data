#include<bits/stdc++.h>
using namespace std;
const long long P=2e5+5;
long long num[P],ans=0,sum[31];
bool log2(long long x){
	if(x<=128){
		for(int i=0;i<=7;i++){
		    if(x==sum[i])return true;
	    }
	}else if(x>128&&x<=pow(2,15)){
		for(int i=8;i<=15;i++){
		    if(x==sum[i])return true;
	    }
	}else{
		for(int i=15;i<=30;i++){
		    if(x==sum[i])return true;
	     }
	}
	return false;
}
bool cmp(long long x,long long y){
	if(!log2(y)==false&&log2(x)==true)return y>x;
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	sum[0]=1;
	for(int i=1;i<=30;i++)sum[i]*=2;
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>num[i];
	sort(num+1,num+n+1,cmp);
	if(k==1){
		cout<<num[n];
		return 0;
	}else{
	    ans=num[1];
		for(int i=2;i<=k;i++){
			cout<<num[i]<<" ";
			ans=(num[i]&ans);
		}
	}
	cout<<ans;
	return 0;
}
