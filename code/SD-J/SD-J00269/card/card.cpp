#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=5e5+10;
int n,m;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;return 0;
	}
	if(m==2){
		int res1=0,res2=0;
		int x=0,y=0;
		for(int i=0;i<n;i++){
			for(int j=i;j<=n;j++){
				if(x!=0||y!=0){
					y=0,x=0;
				}
				if(a[i]==1) x=1;
				if(a[i]==2) y=1;
			}
			res1+=x,res2+=y;
		}
		cout<<res1<<" "<<res2;return 0;
	}
	
	return 0;
}

