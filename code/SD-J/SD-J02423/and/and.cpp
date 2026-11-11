#include<bits/stdc++.h>
using namespace std;

int a[200005];
int n,m;
int ans=0,sum=0,cnt=0,M=0x3f3f3f;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+1+n,cmp);
	
	if(m==1){
		cout<<a[1];
		return 0;
	}
	
	ans=a[1]&a[2];

	int last=3;
	int k=0;
	for(int i=1;i<=m-2;i++){
		for(int j=last;j<=n;j++){
			if(abs(ans-a[j])<M){
				M=abs(ans-a[j]);
				k=j;
			}
		}
		ans= ans&a[k];
		last=a[k];
	}
	
	cout<<ans;
	
	
	return 0;
} 


