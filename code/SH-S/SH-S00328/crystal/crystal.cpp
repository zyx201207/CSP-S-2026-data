#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
unordered_map<long long,int> ma;
long long a[N],s1[N];
int n;
long long m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int ans=0;
	bool flag=0;
	long long mina=LONG_LONG_MAX;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma[a[i]]++;
		mina=min(mina,a[i]);
		if(a[i]>100 || a[i]<-100) flag=1;
	}
	sort(a+1,a+1+n);
	long long b=a[2]-a[1];
	bool f=0;
	for(int i=2;i<n;i++){
		if(a[i+1]-a[i]!=b){
			f=1;
			break;
		}
	}
	if(!f){
		long long s=0;
		while(ans<n){
			if(s+b*ans<=m){
				s+=b*ans;
				ans++;
			}
			else break;
		}
	}
	else if(!flag){
		for(int i=1;i<=n;i++){
			int t=0;
			long long s=0;
			for(int j=a[i];j>=mina;j--){
				if(ma[j]){
					if(s+(a[i]-j)*ma[j]<=m) {
						t+=ma[j];
						s+=(a[i]-j)*ma[j];
					}
					else if(s+m/(a[i]-j)*(a[i]-j)<=m){
						t+=m/(a[i]-j);
						s+=m/(a[i]-j)*(a[i]-j);
					}
					else break;
				}
			}
			ans=max(ans,t);
		}
	}
	else{
		for(int i=1;i<=n;i++){
			int c=0;
			for(int j=1;j<=n;j++){
				if(a[i]>=a[j]) s1[++c]=a[i]-a[j];
			}
			sort(s1+1,s1+1+c);
			int t;
			for(int j=1;j<=c;j++){
				s1[j]=s1[j-1]+s1[j];
				if(s1[j]>m){
					t=j-1;
					break;
				}
			}
			if(t>ans) ans=t;
		}
	}
	cout<<ans;
	return 0;
} 
