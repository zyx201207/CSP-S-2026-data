#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100001],ans,sum,maxx=-INT_MAX;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	int x=0;
	for(int i=1;i<=n;i++){
		x+=a[i]; 
	}
	x/=n;
	for(int i=1;i<=n;i++){
		if(i==x){
			ans=i;
			break;
	    }
    }
    while(1){
    	for(int i=ans-1;i>=1;i--){
    		if(m<=0){
    		m=-7891;
			}
			while(a[i]!=x){
				if(m<=0) break;
				m--;
				a[i]++;
			}
		}
		if(m==-7891) break;
		ans++;
 	}
 	sum=1;
 	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
	//	cout<<a[i]<<" ";
		if(a[i]==a[i-1]){
			sum++;
		}else{
			maxx=max(maxx,sum);
			sum=0;
		}
	}
	cout<<maxx;
	return 0;
}

