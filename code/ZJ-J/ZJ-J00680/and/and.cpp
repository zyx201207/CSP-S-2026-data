#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,m,a[200005],maxx=-1,andcnt,cnt;
int andnon(int x){
	int usecnt;
		for(int i=1;i<=n;i++){
			if(i==1&&x==1){
				usecnt=a[2]&a[3];
				i=4;
				x=n+10;
			}
			if(i!=x) usecnt=usecnt&a[i];
	}
	return usecnt;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	andcnt=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		andcnt=andcnt&a[i];
		if(a[i]>maxx) maxx=a[i];
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==n){
		cout<<andcnt;
		return 0;
	}
	if(m==n-1){
		maxx=-1;
		for(int i=1;i<=n;i++){
			if(andnon(i)>maxx) maxx=andnon(i);
		}
		return 0;
	}
	if(m==2){
		maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>maxx) maxx=a[i]&a[j];
			}
		}
		cout<<maxx;
		return 0;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}