#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
bool flag[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		flag[i]=false;
	}
	int ans=0;
	for(int j=29;j>=0;j--){
		int bit=(1<<j);
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(flag[i])continue;
			if(a[i]&bit)cnt++;
		}
//		cout<<j<<' '<<cnt<<endl;
		if(cnt>=m){
			for(int i=1;i<=n;i++){
				if((a[i]&bit)==0)flag[i]=true;
			}
			ans+=bit;
		}
	}
	cout<<ans<<endl;
	return 0;
}

