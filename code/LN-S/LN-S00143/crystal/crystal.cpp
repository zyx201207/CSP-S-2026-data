#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+4;
int n,m,pj,sum,w,cnt = 0,j;
int a[N],c[N];
bool cmp(int x,int y){
	return x < y; 
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w".stdout);
	cin>>n>>m;
	j = m;
	for(int i = 0;i < n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	pj = sum / n;
	for(int i = 0;i < n;i++){
		if(a[i] <= pj){
			c[w] = a[i] - pj;
			w++;
		}
	}
	sort(c,c+w,cmp);
	for(int i = 0;i < n;i++){
		if(c[i]>0){
			j -= c[i];
		}
		if(c[i] <= 0){
			j += c[i];
		}
		cnt++;
		if(j <= 0) {
			cout<<cnt+1;
			return 0;
		}
	}
	
}
