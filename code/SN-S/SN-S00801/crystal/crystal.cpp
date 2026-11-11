#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10;
int n;int m;
int a[N],c[N];
bool cmp(int a,int b){
	return a<b;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 1; i<= n; i++){
		cin>>a[i]; 
		
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1; i<= n; i++){
		c[i] = a[i]-a[i-1];
	}
	int asd = 0;
	int maxx=  -1;
	for(int i = 2,l=1; i<= n&&l<=i; i++){
		asd = asd+(i-1)*c[i];
		if(asd<=m){
			maxx = max(maxx,i-l+1);
		}else{
			while(asd>m){
				asd=asd-(a[i]-a[l]);
				l++;
			}
			
		}
	}
	cout<<maxx;
	return 0;
}
