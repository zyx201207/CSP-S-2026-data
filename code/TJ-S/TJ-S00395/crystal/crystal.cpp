#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	ll ans=0;
	cin>>n>>m;
	vector<ll>a(n);
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	ll k=a[(n+1)/2-1];
	ll l=(n+1)/2-2,r=(n+1)/2,l1,r1;
	ll sum=0;
	while(1) {
		l1=abs(k-a[l]),r1=abs(a[r]-k);
		if(l-1!=-1&&r+1!=n) {
			if(sum+l1+r1<=m) {
				sum+=l1+r1;
				ans+=2;
			} else if(sum+l1<=m) {
				sum+=l1;
				ans+=1;
			} else if(sum+r1<=m) {
				sum+=r1;
				ans+=1;
			} else if(sum+l1>m&&sum+r1>m) {
				break;
			}
			l--;
			r++;
		} else if(l-1==-1&&r+1!=n) {
			if(sum+r1<=m) {
				sum+=r1;
				ans+=1;
			}
			r++;
		} else if(l-1!=-1&&r+1==n) {
			if(sum+l1<=m) {
				sum+=l1;
				ans+=1;
			}
			l--;
		} else {
			break;
		}
	}
	if(sum+l1+r1<=m) {
		sum+=l1+r1;
		ans+=2;
	} else if(sum+l1<=m) {
		sum+=l1;
		ans+=1;
	} else if(sum+r1<=m) {
		sum+=r1;
		ans+=1;
	}
	cout<<ans+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

