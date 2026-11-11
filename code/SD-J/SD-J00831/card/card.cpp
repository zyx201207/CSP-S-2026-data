#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[5*100000+5];
int b[5*100000+5];
int tp[5*100000+5],cnt=0;
void run(int q){
	for(int i=1;i<=cnt;i++) tp[i]=0;
	cnt=0;
	for(int i=q;i<=n;i++){
		int pos=0;
		for(int j=1;j<=cnt;j++){
			if(tp[j]==a[i]){
				pos=j;
				break;
			}
		}
		if(pos!=0){
			for(int j=pos;j<=cnt;j++){
				tp[j]=0;
			}
		}
		if(pos!=0){
			cnt=pos;
			tp[cnt]=a[i];
		}
		else{
			tp[++cnt]=a[i];
		}
//		for(int j=1;j<=cnt;j++) cout<<tp[j]<<" ";
//		cout<<'\n';
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		
		run(i);
		for(int j=1;j<=cnt;j++){
//			cout<<tp[j]<<" ";
			b[tp[j]]++;
		}
//		cout<<'\n';
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
