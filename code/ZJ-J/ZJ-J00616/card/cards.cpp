#include<bits/stdc++.h>
using namespace std;
int n,m,a[200008],b[200008],sum=0,d[200008],mm;
void cl(){
	int c[200008]={0},s;
	for(int i=1;i<=sum;i++){
		c[b[i]]++;
		if(c[i]==2){
			s=i;
			break;
		}
	}
	bool p=false;
	int ss=sum;
	for(int i=1;i<=ss;i++){
		if(b[i]==s){
			if(p){
				p=false;
			}else{
				p=true;
			}
		}
		if(!p){
			sum--;
		}
	}
	sum++;
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mm=max(mm,a[i]);
	}
	for(int i=1;i<=m;i++){
		sum=0;
		for(int j=i;j<=n;j++){
			sum++;
			b[sum]=a[j];
			cl();
		}
		for(int j=1;j<=sum;j++){
			d[b[j]]++;
		}
	}
	for(int i=1;i<=mm;i++){
		cout<<d[i]<<" ";
	}
}