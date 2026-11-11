#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long ans=0;
struct node{
	long long cnt;
	char c;
}a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].c;
	}
	bool fl=true;
	for(int i=1,fi=n;i<=fi;i++,fi--){
		if(a[i].c!=a[fi].c){
			fl=false;
			if(a[i].cnt<=a[fi].cnt){
				a[i].c=a[fi].c;
				ans+=a[i].cnt;
			}else{
				a[fi].c=a[i].c;
				ans+=a[fi].cnt;
			}			
		}
	}
	if(fl==true){
		cout<<0;
		return 0;
	}
	fl=true;
	for(int i=1,fi=n;i<=fi;i++,fi--){
		if(a[i].cnt!=a[fi].cnt){
			fl=false;
			if(a[i].cnt<a[fi].cnt){
				int t=a[fi].cnt-a[i].cnt;
				a[fi].cnt=a[i].cnt;
				a[fi-1].cnt+=t;
				ans+=t;
			}else{
				int t=a[i].cnt-a[fi].cnt;
				a[i].cnt=a[fi].cnt;
				a[fi-1].cnt+=t;
				ans+=t;
			}			
		}
	}
	cout<<ans;
	return 0;	
}