#include<bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define re register

using namespace std;

const ULL N=5e5+5;
const LL inf =(LL)0x3f3f3f3f3f3f3f3f;

int n;
LL m,a[N];
int ans=(int)-inf;

bool check_(int x,int y,LL k){
	LL s=0;
	for(re int i=x;i<=y;i++){
		s+=abs(a[i]-k);
	}
	return s<=m;
}

bool check(int x,int y){
	LL l=a[x],r=a[y];
	while(l<=r){
		LL mid=(l+r)/2;
		if(check_(x,y,mid)){
			return 1;
		}
		else{
			r=mid-1;
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(re int i=1;i<=n;i++){
		cin>>a[i];
	}

	stable_sort(a+1,a+1+n);
	for(re int i=1;i<=n;i++){
		int l=i+1,r=n;
		while(l<=r){
			int mid=(r+l)/2;
			//if(mid==l) break;
			//cout<<l<<" "<<r<<"\n";
			if(check(i,mid)){
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		cout<<i<<" "<<l-1<<'\n';
		ans=max(ans,l-i);
	}

	cout<<ans;
	return 0;
}