#include <bits/stdc++.h>
using namespace std;
struct str{
	int ai;
	char c;
}a[200005];
//int su[200005]={};
long long ans=0,len,n,k,l,r;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++){
		char c;
		cin>>a[i].ai>>a[i].c;
		len+=a[i].ai;
		//if(i==0) su[i]=a[i];
		//else su[i]=su[i-1]+a[i];
	}
	l=0,r=n-1;
	while(l<r){
		if(a[l].c!=a[r].c){
			if(a[l].ai<a[r].ai){
				ans+=a[l].ai;
				a[r].ai-=a[l].ai;
				l++;
			}else{
				ans+=a[r].ai;
				a[l].ai-=a[r].ai;
				r--;
			}
		}else{
			if(a[l].ai<a[r].ai){
				a[r].ai-=a[l].ai;
				l++;
			}else{
				a[l].ai-=a[r].ai;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
