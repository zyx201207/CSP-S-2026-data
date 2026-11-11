#include<bits/stdc++.h>
using namespace std;
#define int long long
const int A=3e5+10;
int t[A],h[A],ans[A],v[A],n,m;

void f(int p){
	memset(v,0,sizeof(v));
	memset(t,0,sizeof(t));
	int cnt=1,cnt1=1;
	for(int i=p;i<=n;i++){
		t[cnt1]=h[i];
		if(v[h[i]]!=0){
			cnt=v[h[i]];
			for(int j=v[h[i]];j<=cnt1;j++){
				v[t[j]]=0;
				t[j]=0;
			}
			cnt1=cnt;
			t[cnt1]=h[i];
			v[h[i]]=cnt1;
		}
		else{
			v[h[i]]=cnt1;
		}
		cnt1++;
		cnt++;
	}
	for(int i=1;i<=cnt1;i++){
		ans[t[i]]++;
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	for(int i=1;i<=n;i++){
		f(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
} 
