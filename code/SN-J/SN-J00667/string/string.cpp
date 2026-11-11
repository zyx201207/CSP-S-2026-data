//赵晗羽 西安辅轮中学  SN-J00667 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int s;
struct st{
	int o;
	char c;
}a[200005]; 
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].o>>a[i].c;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].o>a[r].o){
			if(a[l].c!=a[r].c)s+=a[r].o;
			a[l].o-=a[r].o;
			r--;		
		}
		if(a[r].o>a[l].o){
			if(a[r].c!=a[l].c)s+=a[l].o;
			a[r].o-=a[l].o;
			l++;		
		}
		if(a[l].o==a[r].o){
			if(a[l].c!=a[r].c)s+=a[r].o;
			l++,r--;		
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

