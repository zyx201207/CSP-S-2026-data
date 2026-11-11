#include<bits/stdc++.h>
using namespace std;

long long n,m,a[1000086],b[1000086],s[1000086]; 

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		int l=0;
		b[++l]=a[i];
		for(int j=i+1;j<=n;j++){
			int f=0;
			for(int k=1;k<=l;k++){
				if(a[j]==b[k]){
					f=1;
				}
				if(f){
					b[k]=0;
				}
			}
			b[++l]=a[j];
		}
		for(int k=1;k<=l;k++){
			s[b[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0;
}
