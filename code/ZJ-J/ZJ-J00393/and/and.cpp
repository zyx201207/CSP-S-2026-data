#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[1000001];
int ans;
int f;
vector<int> v[500001];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int pos=0;
	for(int i=30;i>=0;i--){
		if(a[1]<pow(2,i)){
			continue;
		}
		int cnt=0;
		int newpos=0;
		for(int j=1;j<=n;j++){
			if((a[j])&((int)pow(2,i))){
				cnt++;
				newpos=j;
			}
			if(cnt>=m&&(newpos<=pos||f==0)){
				if(!f)pos=newpos;
				f=1;
				ans+=(int)pow(2,i);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
//Trick||Treat!