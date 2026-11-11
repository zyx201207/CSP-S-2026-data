#include<bits/stdc++.h>
#include<cstdio>
#define int long long
#define endl '\n'
#define Fre
#define Ct

const int N=2e5+10;

using namespace std;

typedef pair<int,int> PII;

int a[N];
char c[N];

void solve(){
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				
				a[l]-=a[r];r--;
			}
			else if(a[l]==a[r]){
				l++;
				r--;
			}
			else{
				
				a[r]-=a[l];l++;
			}
		}
		else{
			if(a[l]>a[r]){
			
				a[l]-=a[r];
				sum+=a[r];	r--;
			}
			else if(a[l]==a[r]){
				
				sum+=a[l];l++,r--;
			}
			else{
			
				a[r]-=a[l];
				sum+=a[l];	l++;
			}
		}
	}
	cout<<sum<<endl;
}

signed main(){
	
#ifdef Fre
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
#endif

#ifdef Ct
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	int _=1;
	//cin>>_;
	while(_--) solve();
	
	return 0;
}

