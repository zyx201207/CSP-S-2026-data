#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m,a[250000]={0},b[250000]={0},y=0;
	long long cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n==1){
		cout<<1;
		return 0;
	}
	int ans=0;
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
		ans++;
	}
	int y1=1,ans1=m,d=0;
	for(int j=1;j<ans;j++){
		for(int i=1;i<=ans;i++){
			if(ans1>=b[i]*i){
				ans1-=b[i]*i;
				y1++;
			}
			else{
				y=max(y,y1);
				y1=1;
				d++;
				continue;
			}
		}	
	}
	cout<<y;
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
