#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,res=1;
int a[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int M=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		m=M;
		int it=i;
		//cout<<"!it:"<<it<<endl;
		while(m>=0){
			it--;
			if(it<=0) break;
			m-=abs(a[it]-a[i]);
			//cout<<"	 "<<it<<" "<<m<<endl;
		}
		//cout<<"end:"<<m<<" "<<i-it<<endl;
		res=max(res,i-it);
	}
	cout<<res<<endl;
	return 0;
}
