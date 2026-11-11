#include<bits/stdc++.h>
using namespace std;
struct str1{
	int lenth;
	char type;
}a[200010]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].lenth>>a[i].type;
	}
	long long ans=0;
	int l=1,r=n;
	int lenth_l=a[1].lenth,lenth_r=a[n].lenth;
	char type_l=a[1].type,type_r=a[n].type;
	while(r>l){
		if(lenth_l==0){
			++l;
			lenth_l=a[l].lenth;
			type_l=a[l].type;
		}
		if(lenth_r==0){
			--r;
			lenth_r=a[r].lenth;
			type_r=a[r].type;
		}
		if(l>r) break; 
		if(type_l!=type_r){
			ans+=min(lenth_l,lenth_r);
		}
		if(lenth_l>=lenth_r){
			lenth_l-=lenth_r;
			lenth_r=0;
		}else{
			lenth_r-=lenth_l;
			lenth_l=0;
		}
	}
	cout<<ans;
	return 0;
}
