#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n;
struct node{
	int v;
	char p;
}a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].v>>a[i].p;
	}	
	int cnt=0;
	for(int i=1,j=n;i<j;){
		if(a[i].p==a[j].p){
			if(a[i].v>a[j].v){
				a[i].v-=a[j].v;
				j--;
			}
			else{
				a[j].v-=a[i].v;
				i++;
			}
		}
		else{
			if(a[i].v>a[j].v){
				a[i].v-=a[j].v;
				cnt+=a[j].v;
				j--;
			}
			else{
				a[j].v-=a[i].v;
				cnt+=a[i].v;
				i++;
			}
		}
	}
	cout<<cnt;
	
	
	
	
	return 0;
}