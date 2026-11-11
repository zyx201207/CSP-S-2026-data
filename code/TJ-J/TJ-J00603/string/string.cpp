#include<bits/stdc++.h>
using namespace std;

struct node{
	long long num;
	char data;
}a[200050];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].data;
	}
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		long long minu=0;
		if(a[l].data==a[r].data){
			minu=min(a[l].num,a[r].num);
			a[l].num-=minu;
			a[r].num-=minu;
		}
		else{
			minu=min(a[l].num,a[r].num);
			a[l].num-=minu;
			a[r].num-=minu;
			ans+=minu;
		}
		if(a[l].num==0) l++;
		if(a[r].num==0) r--;
		
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
