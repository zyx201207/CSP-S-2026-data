#include<bits/stdc++.h>
using namespace std;
int n,m,a[200050],ans=0xffffffff;
bool cmp(int a,int b){
	int x=0,y=0;
	while(a){
		x+=a&1;
		a=a>>1;	
	}
	while(b){
		y+=b&1;
		b=b>>1;	
	}
	return x>y;	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;	
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	} 
	sort(a,a+n,cmp);
	for(int i=0;i<m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
} 
