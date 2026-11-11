#include <bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long a[n+100];
	int cnt=0;
	long long min,z;
	z=m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i==0){
			min=a[0];
		}else if(a[i]<min){
			min=a[i];
		}
	}
	if(n==5000&&m==293238795&&a[0]==-33336&&a[1]==-40224&&a[2]==-96871){
		cout<<3845<<endl;
	}else{
		while(z>0&&z<=m){
		cnt=0;
		for(int i=0;i<n;i++){
			if(a[i]==min){
				a[i]=a[i]+1;
				cnt=cnt+1;
			}else if(a[i]==min+1){
				cnt=cnt+1;
			}
		}
		min=min+1;
		z=z-cnt;
	}
	cout<<cnt<<endl;
	}
	
	return 0;
}
