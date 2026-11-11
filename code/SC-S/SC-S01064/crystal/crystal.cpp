#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int j=1;
	for(int i=1;i<=n;i++){
		if(abs(a[i]-a[i-1])<=a[i+1]-a[i]){
			    while(j<m&&a[i]!=a[i-1]){
			        a[i-1]++;
			        j++;
		        }
		        if(a[i]==a[i-1])ans++;	
	    }else{
	    	while(j<m&&a[i]!=a[i+1]){
	    		a[i]++;
	    		j++;
			}
			if(a[i]==a[i+1])ans++;
		}
	}
	cout<<ans;
	return 0;
}
