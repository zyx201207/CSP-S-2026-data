#include<bits/stdc++.h>
using namespace std;
int pa(int*a,int b){
	int ans = 0;
	for(int i = 0;i<b;i++){
		ans = ans & a[i];
	}
	return ans;
}
int main(){
	int a,b;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);;
	cin>>a>>b;
	int c[a];
	for(int i = 0;i<a;i++){
		cin>>c[i];
	}
	if(b == 1){
		sort(c,c+a);
		cout<<c[a-1];
	}
	else if(b == a){
		cout<<pa(c,a);
	}
	else{
		int ans[a*a]{0};
		for(int i = 0;i<a;i++){
			for(int n = 0;n<a;n++){
				if(i != n ){
					ans[i*a+n] = c[i] & c[n];
				}
			}
		}
		sort(ans,ans+a*a);
		cout<<ans[a*a-1];
	}
	return 0;
}
