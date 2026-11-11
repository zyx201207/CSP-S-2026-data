#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long a[200005],s[200005]={0};
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>m>>n;
	for(int i=0;i<m;i++){
		cin>>a[i];
		int k=a[i];
		while(k>0){
			if(!(k&1))s[i]++;
			k>>=1;
		}
	}
		for(long long i=1;i<m;i++){
			if(s[i]<s[i-1]){
				swap(s[i],s[i-1]);
				swap(a[i],a[i-1]);
			}
		}
	}
	long long ans=a[0];
	for(int i=1;i<n;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}