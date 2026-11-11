#include<bits/stdc++.h>
using namespace std;

long long n,j7,a[200010],vi[200010],j6,j5,o,h;
void dfs(long long j3){
	if(j3==j7+1){
		o=0;
		for(int i=0;i<n;i++){
			if(vi[i]==1){
				if(o==0){
					j5=a[i];
					o=1;
				}
				if(o==1){
					j5&=a[i];
				}
			}
		}
		j6=max(j6,j5);
		return;
	}
	for(int i=0;i<n;i++){
		if(vi[i]==0){
			vi[i]=1;
			dfs(j3+1);
			vi[i]=0;
			
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>j7;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=20){
	dfs(1);
	h=1;
	}
	if(j7==1){
		for(int i=0;i<n;i++){
			j6=max(a[i],j6);
			cout<<j6;
			return 0;
		}
	}
	if(n==j7){
		j6=a[0];
		for(int i=0;i<n;i++){
			j6&=a[i];
		}
		cout<<j6;
		return 0;
	}
	if(h==0){
		for(int i=0;i<n;i++){
			o=min(o,a[i]);
		}
	for(int i=0;i<n;i++){
		while(a[i]>=1){
		if(a[i]%2==0){
			break;
	
		}
		a[i]=(a[i]-1)/2;
		}
	}
	cout<<o;
	return 0;
	}
	
	cout<<j6;
	return 0;
}
