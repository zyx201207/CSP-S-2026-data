#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=500005;
ll n,m;
int a[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int fa=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		//A
		if(i!=0&&a[i]!=a[i-1]){
			fa=0;
		}
	}
	//A
	if(fa){
		cout<<n;
		return 0;
	}
	//B
	sort(a,a+n);int fb=1;
	for(int i=0;i<n;i++){
		if(i!=0&&i!=1&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
			fb=0;
		}
	}
	if(fb){
		ll k=a[1]-a[0],cnt=0,ans=0;
		for(int i=0;i<n;i++,ans++){
			cnt+=k;m-=cnt;
			if(m<0){
				break;
			}
		}cout<<ans;
		return 0;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		int l=i-1,r=i+1,cnt=1,m_=m;
		while(l>=0){
			m_-=a[i]-a[l];l--;
			if(m_<0){
				break;
			}
			cnt++;
		}
		ans=max(ans,cnt);
		//cout<<"i="<<i<<"cnt="<<cnt<<endl;
		if(ans==n){
			break;
		}
	}
	cout<<ans;
}
