#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	char c;
}da[200005];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>da[i].a>>da[i].c;
	}
	int k=1,len=n;
	long long ans=0;
	while(k<=len){
		if(da[k].a>da[len].a){
			if(da[k].c!=da[len].c){
				ans+=da[len].a;
	 		} 
			da[k].a-=da[len].a;
			len--; 
		}
		else if(da[k].a<da[len].a){
			if(da[k].c!=da[len].c){
				ans+=da[k].a;
	 		} 
			da[len].a-=da[k].a;
			k++; 
		}
		else{
			if(da[k].c!=da[len].c){
				ans+=da[k].a;
	 		} 
	 		len--;
			k++; 
		}
	}
	cout<<ans;
	
	return 0;
} 
