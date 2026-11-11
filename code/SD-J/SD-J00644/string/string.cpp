#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
struct node{
	char c;
	int data;
}a[N];
int n;
ll ans;
int r;
char now;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].data>>a[i].c;
	}
	r=n;
	for(int i=1;r>=i;i++){
		if(a[i].c!=a[r].c){
			if(a[i].data<=a[r].data){
				ans+=a[i].data;
				a[r].data-=a[i].data;
			}
			else{
				ans+=a[r].data;
				a[i].data-=a[r].data;
				a[r].data=0;
				i--;
			}
			if(a[r].data==0){
				r--;
			}
		}
		else{
			if(a[i].data<=a[r].data){
				a[r].data-=a[i].data;
			}
			else{
				a[i].data-=a[r].data;
				a[r].data=0;
				i--;
			}
			if(a[r].data==0){
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}

