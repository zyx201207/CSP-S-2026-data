#include<bits/stdc++.h>
using namespace std;
#define i64 long long
const int N=2e5+5;
struct node{
	i64 len;
	char c;
}a[N];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c;
	}
	int l=1,r=n;
	i64 ans=0;
	while(l<r){
		if(a[l].c!=a[r].c){
			if(a[l].len>a[r].len){
				a[l].len-=a[r].len;
				ans+=a[r].len;
				r--;
			}else{
				a[r].len-=a[l].len;
				ans+=a[l].len;
				l++;	
			}			
		}else{
			if(a[l].len>a[r].len){
				a[l].len-=a[r].len;
				r--;
			}else{
				a[r].len-=a[l].len;
				l++;	
			}	
		}
	}
	cout<<ans;
	return 0;
}

