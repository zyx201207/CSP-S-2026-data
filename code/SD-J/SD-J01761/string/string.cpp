#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T;
struct node{
	int t;
	char x;
}a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>a[i].t>>a[i].x;
	}
	long long ans=0;
	int l=1,r=T;
	while(l<r){
		if(a[l].x!=a[r].x){
			if(a[l].t>a[r].t){
				ans+=a[r].t;
				a[l].t-=a[r].t;
				a[r].t=0;
				r--;
			}else if(a[l].t==a[r].t){
				ans+=a[l].t;
				l++,r--;
			}else{
				a[r].t-=a[l].t;
				ans+=a[l].t;
				a[l].t=0;
				l++;
			}
		}else{
			if(a[l].t>a[r].t){
				a[l].t-=a[r].t;
				a[r].t=0;
				r--;
			}else if(a[l].t<a[r].t){
				a[r].t-=a[l].t;
				a[l].t=0;
				l++;
			}else{
				l++,r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
¹À·Ö 100 
*/
