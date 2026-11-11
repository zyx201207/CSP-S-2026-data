#include<bits/stdc++.h>
using namespace std;
#define int long long
struct stu{
	int x;
	char c;
}a[200025];
int n;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	int ans=0;
	for(int i=1,j=n;;){
		if(i>=j)break;
		if(a[i].x<a[j].x){
			if(a[i].c!=a[j].c){
				ans+=a[i].x;
			}
			a[j].x-=a[i].x; i++;
		}else if(a[i].x==a[j].x){
			if(a[i].c!=a[j].c){
				ans+=a[i].x;
			}
			i++,j--;
		}else{
			if(a[i].c!=a[j].c){
				ans+=a[j].x;
			}a[i].x-=a[j].x; j--;
		}
	}cout<<ans;
	return 0;
}
