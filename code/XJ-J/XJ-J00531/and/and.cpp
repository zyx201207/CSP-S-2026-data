#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn];
int ai=1;
bool cmp(int aa,int bb){
	return aa<bb;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[ai++]=a[i]%2;
	}
	sort(a+1,a+1+ai,cmp);
	int minx=1e6;
	for(int i=1;i<=n;i++){
		if(a[ai]<minx){
			minx=a[ai];
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i];
		break;
	}
	
	return 0;
}