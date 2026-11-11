#include<bits/stdc++.h>
using namespace std;
int n;
bool f=true;
long long m,a[500005],l[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long b;
	b=a[n]-a[n-1];
	for(int i=1;i<=n-1;i++){
		if(a[i+1]-a[i]!=b){
			f=false;
			break;
		}
	}
	for(int i=n;i>=1;i--){
		if(a[i]==a[i-1]){
			int j=i;
			while(a[j]==a[j-1]){
				l[i]++;
				j--;
			}
			i=j-1;
		}
	}
	if(f==true){
		long long ss=0; 
		for(int i=1;;i++){
			ss+=i;
			if(ss>m/b||i==n){
				cout<<i;
				return 0;
			}
		}
	}
	long long maxn=-1;
	for(int i=n;i>=2;i--){
		int s=0;
		for(int j=i-l[i];;j--){
			s+=a[i]-a[j];
			if(s>m){
				if(i-j>maxn) maxn=i-j;
				break;
			}
			else if(j==1){
				if(i>maxn) maxn=i;
				break;
			}
		}
		if(l[i]>0){
			i-=l[i];
		}
	}
	cout<<maxn;
	return 0;
}
