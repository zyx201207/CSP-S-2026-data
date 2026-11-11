#include <bits/stdc++.h>
using namespace std;
int m,n,b,ans=1,a[10086],cha[10086];
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m ;
	for(int i = 1;i <= n;i++){
		cin >> a[i]; 
	}
	for(int i = 1;i <= n;i++){
		cha[i]=a[i+1]-a[i]; 
	}
	sort(a+1,a+n+1);
	a[n+1]=1000000;
	while(m--){
	for(int i = 1;i <= n;i++){
	b=cha[1];
		if(a[i]+1==a[i+1]){
			a[i]=a[i]+1	;
		}
		
		else a[1]=a[1]+1;
		sort(a+1,a+n+1);
	}
    }
    for(int i = 1;i <= n;i++){
    	if(a[i]=a[i+1])ans++; 
	}
	cout << ans-n+2<<endl;
	for(int i = 1;i <= n;i++){
		cout << a[i] << " "; 
	}
	return 0;
}
