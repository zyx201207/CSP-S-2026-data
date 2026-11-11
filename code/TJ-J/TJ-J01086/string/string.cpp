#include<bits/stdc++.h>
using namespace std;
struct q{
	long long v;
	char s;
}a[200010];
unsigned long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].v>>a[i].s;
		
	}
	for(int i=1;i<=n;i++){
		
	}
	int l=1;
	int r=n;
	ans=0;
	while(l<r){
		if(a[l].s!=a[r].s){
			if(a[l].v>a[r].v){
				ans+=a[r].v;
				a[l].v-=a[r].v;
				r--;
			}else if(a[l].v==a[r].v){
				ans+=a[r].v;
				r--;
				l++;
			}
			else if(a[l].v<a[r].v){
				ans+=a[l].v;
				a[r].v-=a[l].v;
				l++;
			}
		}else if(a[l].s==a[r].s){
			if(a[l].v>a[r].v){
				a[l].v-=a[r].v;
				r--;
			}else if(a[l].v==a[r].v){
				r--;
				l++;
			}
			else if(a[l].v<a[r].v){
				a[r].v-=a[l].v;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
