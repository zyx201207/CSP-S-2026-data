#include<bits/stdc++.h>
using namespace std;
int n,ans,l;
long long m,a[500010],cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ch=a[2]-a[1],l=a[2];
	bool f=1;
	if(n>2){
		for(int i=3;i<=n;i++){
			if(a[i]-l!=ch){
				f=0;
				break;
			}
			l=a[i];
		}	
	}
	if(f){
		for(int i=1;i<=n;i++){
			cnt+=(i-1)*(a[i]-l);
			l=a[i];
			if(cnt>m)break;
			ans=max(ans,i);
		}
		cout<<ans;
	}else{
		for(int h=1;h<=n;h++){
			for(int i=h;i<=n;i++){
				cnt+=(i-1)*(a[i]-l);
				l=a[i];
				if(cnt>m)break;
				ans=max(ans,i-h+1);
			}
		}
		cout<<ans;
	}
	
}
//gugugaga gugugaga gugugaga!!!
