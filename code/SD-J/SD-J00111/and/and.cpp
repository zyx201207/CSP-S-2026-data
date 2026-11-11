#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int N=2*1e5+10;
int n,m;
int a[N];
int s;
int h;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		int k=a[i];
		while(k>1){
			if(k%2==1){
				h=i;
				s=a[i];
				for(int i=h-1;i>=h-m+1;i--){
					s&=a[i];
				}
				cout<<s<<endl;
				return 0;	
			}
			k/=2;
		}
	}
	return 0;
}
