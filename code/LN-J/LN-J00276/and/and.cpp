#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m;
int a[N];
int ma;
int maa;
int s;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=0;i<n;i++){
			ma=max(ma,a[i]);
		}
		cout<<ma;
		return 0;
	}
	
	if(m==n){
		int x;
		x=a[0];
		for(int i=1;i<n;i++){
			x&=a[i];
		}
		cout<<x;
		return 0;
	}
	if(m==2){
		
		for(int i=0;i<n;i++)
		{
			s=a[i];
			for(int j=i+1;j<n;j++){
				s&=a[j];
				ma=max(ma,s);
			}
		}
		cout<<ma;
		return 0;
	}
	sort(a,a+n,cmp);
	int ss=a[0];
	for(int i=1;i<m;i++){
		ss&=a[i];
	}
	cout<<ss;
	return 0;
}
