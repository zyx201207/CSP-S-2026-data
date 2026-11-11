#include<bits/stdc++.h>
using namespace std;
int m,n;
const int N=1e6+1;
int a[N];
int b[N]={0};
int c[N]={0};
bool su[N];
int num=0;
int mx=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				cout<<a[i];
				return 0;
			}
		}
	}
	
	return 0;
}
