#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
long long cnt[N];
long long sum,ans;
int n;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	string s=" ";
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		cnt[i]=sum;
		sum+=a[i];
		s+=c;
		
	}
	int l=1,r=n;
	long long lx,ly,rx,ry;
	long long x;
	while(l<r){
		lx=cnt[l]+1;
		ly=cnt[l]+a[l];
		rx=cnt[r]+1;
		ry=cnt[r]+a[r];
		x=sum-rx+1;
		if(a[l]>=a[r]){
			
			if(s[l]!=s[r]){
				//字母不同
				ans+=a[r];
			}
			a[l]=a[l]-a[r];
			r--;
		}else{
			if(s[l]!=s[r]){
				//字母不同
				ans+=a[l];
			}
			a[r]=a[r]-a[l];
			l++;
		}
		
	}
	cout<<ans;
	return 0;
} 

