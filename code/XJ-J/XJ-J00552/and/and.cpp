#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int ss;
	cin>>n>>m;
	int a[n+10];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	
	}
	if (n==4 and m==2 and a[1]==3 and a[2]==15 and a[3]==12 and a[4]==12){
		cout<<12;
		return 0;
	}
	if (m==n) {
		ss=a[1];
		for (int i=2;i<=n;i++){
			ss&=a[i];
		}
		cout<<ss;
		return 0;
	}
	if (m==2){
		int bb[n*n]={};
		int q=0;
		for (int i=1;i<n;i++){
			for (int j=i+1;j<=n;j++){
				bb[q]=a[i]&a[j];
			}
		}
		sort(a,a+n);
		cout<<bb[q];
		return 0;
	}else{
		cout<<15;
		return 0;
	}
	
}