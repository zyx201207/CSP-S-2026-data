#include<bits/stdc++.h>
using namespace std;
//#define int long long
//signed main()
const int N=2e5+5;
int a[N];
vector<int> t;
int maxx=-1;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		for(int k=0;k<=30;k++){
			if(pow(2,k)-1==a[i]){
				t.push_back(a[i]);break;
			}
		}
	}
	int ans=t[t.size()-1];
	if(m==1){
		cout<<maxx;
		return 0;
	}
	else if(m==2){
		bool flag=0;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[j]&a[i]);
			}
		}
		cout<<ans;
		return 0;
	}
	else if(maxx<4){
		int cnt3=0,cnt2=0,cnt1=0;
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			if(a[i]==3) cnt3++;
			if(a[i]==2) cnt2++;
			if(a[i]==1) cnt1++;
		}
		if(cnt3>m){
			cout<<3;return 0;
		}
		else if(cnt2+cnt3<m){
			cout<<2;return 0;
		}
		else{
			cout<<0;return 0;
		}
	}
	else if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;return 0;
	} 
	sort(t.begin(),t.end());
	sort(a+1,a+1+n);
	if(t.size()>=m){
		ans=t[t.size()-m];
	}
	cout<<ans<<endl;
	return 0;
}

