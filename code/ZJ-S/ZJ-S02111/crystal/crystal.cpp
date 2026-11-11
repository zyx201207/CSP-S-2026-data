#include<bits/stdc++.h>
#define For(i,j,k) for(int i=j;i<=k;i++)
#define ll long long
#define pb push_back
using namespace std;

int n;
long long m;
int ans=-1;
vector<long long>a,b;
///////
map<long long,bool>vis;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a.resize(n+1);
	b.resize(n+1);
	For(i,1,n){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end()+1);
	b[0]=0;
	For(i,2,n){
		int k=m,ank=0;
		for(int j=i;j>=1;j--){
			if(a[i]-a[j]<=k){
				k-=(a[i]-a[j]);
				ank++;
			}
			else break;
		}
		ans=max(ans,ank);
	}
	cout<<ans;
}
