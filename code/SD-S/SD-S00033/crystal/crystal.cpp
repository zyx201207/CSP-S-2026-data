#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n' 
const int N=1e6+6;
int m,n,a[N],ans,s[N],cnt;
set<int>st;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		st.insert(a[i+1]-a[i]);
	}
	if(st.size()==1){
		int k=a[2]-a[1];
		int ll=m/k,op=0;
		for(int i=1;i;i++){
			op++;
			ll-=i;
			if(ll<=0)
				break;
		}
		cout<<op+1;
		exit(0);
	}else{
		for(int i=1;i<=n;i++){
	cnt=0;
	for(int j=i;j>=1;j--){
		cnt+=a[i]-a[j];
		if(cnt>m)break;
		ans=max(ans,i-j+1);
	}
}
cout<<ans;
	}
//	for(int i=1;i<n;i++)
//		s[i]+=a[i+1]-a[i]+s[i-1];
//	for(int i=n-1,j=n-2;i>=1;i--){
//		while(cnt<=m&&j>=0){
////			cnt+=s[i]*2-s[j]-s[j+1];
//			cnt+=s[i]-s[j];	
////			cout<<s[i]<<" "<<cnt<<" "<<s[j]<<endl;
//			j--;
//		}
//		if(j==0)break;
////		if(cnt>m)
//			cnt-=(s[i]-s[i-1])*(i-j-1);
////		cout<<cnt<<endl;
//		ans=max(ans,i-j);
//	}
//	cout<<ans;
	return 0;
}

