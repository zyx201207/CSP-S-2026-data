#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[1000010],b[1000010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	long long num=m;
	int c=1;
	int ans=0;
	int f=1;
	int w=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]-a[i-1];
		if(i>=2){
			if(b[i]!=b[i-1]) f=0;
		}
	}
	if(f){
		f=m/b[2];
		for(int i=1;i<=n;i++){
			if(i<=f){
				c++;
				f-=i;
			}
			else{
				cout<<c;
				return 0;
			}
		}
	}
	for(int i=2;i<=n;i++){
		int v=0;
		c=1;
		num=m;
		for(int j=i;j>=2;j--){
			v+=b[j];
			if(v<=num){
				c++;
				num-=v;
			}
			else {
				ans=max(ans,c);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
