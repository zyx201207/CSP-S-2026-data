#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans,gs1,gs2,gs3,gs0;
bool op=true;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin),freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		gs1+=(a[i]==1),gs2+=(a[i]==2),gs3+=(a[i]==3),gs0+=(a[i]==0);
		if(a[i]>=4)op=false;
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
		cout<<ans;
	}else if(op){
		if(gs3>=m)cout<<3;
		else if(gs3+gs2>=m)cout<<2;
		else if(gs3+gs1>=m)cout<<1;
		else cout<<0;
	}else{
		cout<<a[m];
	}
	return 0;
} 
