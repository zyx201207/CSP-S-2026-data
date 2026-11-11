#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	long long num[200005];
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	long long maxn=0;
	if(m==n){
		long long a=num[0];
		for(int i=1;i<n;i++){
			a&=num[i];
		}
		maxn=a;
	}else if(m==n-1){
		long long a=num[0],b=num[1];
		for(int i=1;i<n-1;i++){
			a&=num[i];
		}
		for(int i=2;i<n;i++){
			b&=num[i];
		}
		if(a>b){
			maxn=a;
		}else{
			maxn=b;
		}
	}else if(m==1){
		for(int i=0;i<n;i++){
			if(num[i] > maxn){
				maxn=num[i];
			}
		}
	}else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				long long a=num[i]&num[j];
				if(a > maxn){
					maxn=a;
				}
			}
		}
	}
	cout<<maxn<<endl;
	return 0;
}
