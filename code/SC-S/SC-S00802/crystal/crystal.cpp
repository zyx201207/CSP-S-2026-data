#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N];
long long cha;
bool flag=true;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) continue;
		if(i==2) cha=a[2]-a[1];
		else{
			if(a[i]-a[i-1]!=cha){
				flag=false;
			}
		} 
	}
	if(flag){
		m/=cha;
		long long sum=0;
		for(int i=1;;i++){
			sum+=i;
			if(sum>m){
				cout<<i;
				return 0;
			}else if(sum==m){
				cout<<i+1;
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);	
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		long long sum=0;
		for(int i=1;i<mid;i++){
			sum+=a[mid]-a[i];
		}
		if(sum>m){
			r=mid+1;
		}else if(sum<m){
			l=mid+1;
		}else{
			l=r=mid;
			break;
		}
	}
	int tmp=l;
	while(a[tmp]==a[l]) l++;
	cout<<l-1;
	return 0;
} 