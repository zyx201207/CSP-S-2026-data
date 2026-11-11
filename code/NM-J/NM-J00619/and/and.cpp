#include<bits/stdc++.h> 
using namespace std;
int n,m,k=0,cnt,ji,x;
int a[200005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	ji=a[0];
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			cnt=max(cnt,ji&a[j]);
			if(ji&a[j]>=cnt) {
				x=j;
			}
		}
		a[x]=0;
		ji=cnt;
		cnt=0;
	}
	cout<<ji;
	return 0;
}
