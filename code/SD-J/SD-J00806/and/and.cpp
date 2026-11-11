#include<bits/stdc++.h>
using namespace std;
int t[200005],y[200005];
long long n;

int fjh(int m,int b){
	int u; 
	if(m>0){
		int q=b;
		while(q<n-m){
			if(t[q]==0&&q>b){
				t[q]=1;
				u=fjh(m-1,q);
				t[q]=0;
			}
			q++;
		}
	}
	else {
		int f;int c=0;
		for(int i=0;i<n;i++){
			if(t[i]==1){
				if(c==0){f=y[i];c=1;}
				else {f&=y[i];}
			}
		}
		if(f>u)u=f;
	}
	return u;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>y[i];
	}
	cout<<fjh(m,-1);
	return 0;
}
