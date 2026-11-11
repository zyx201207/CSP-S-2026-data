#include<bits/stdc++.h>
using namespace std;
int num=1,cnt=0;
int maxn[1000000];
int maxnum=0;
int b(int c[1000000],int f,int t,int e){
	for(int d=e;d<f-t+1;d++){
		num&=c[d];
		t--;
		if(t!=0) {
			b(c,f,t,e+1);
			}
		if(t==0){
			maxn[cnt]=b(c,f,t+1,e-1);
			cnt++;
			}
	}
	for(int w=0;w<1000000;w++){
		maxnum=max(maxnum,maxn[w]);
}
	return maxnum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a=0;
	int s[1000000];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
		}
	cout<< b(s,n,m,a);
	return 0;
	}
