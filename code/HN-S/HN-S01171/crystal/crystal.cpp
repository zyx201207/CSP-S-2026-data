#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,mcnt;
bool oka=true,okb=true;
int a[500010];
int cha[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			oka=false;
		}
	}
	int x=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=x){
			okb=false;
		}
	}
	if(oka==true){ 
		int sum=0,cnt=0;
		for(int i=1;i;i++){
			sum+=i;
			if(sum>m){
				break;
			}
			cnt++;
		}
		cout<<min(n,(cnt+1));
		return 0;
	}
	if(okb==true){
		int sum=0,cnt=0;
		for(int i=a[1];i;i+=x){
			sum+=i;
			if(sum>m){
				break;
			}
			cnt++;
		}
		cout<<min(n,(cnt+1));
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		memset(cha,0,sizeof(cha));
		for(int j=1;j<i;j++){
			cha[j]=a[i]-a[j];
		}
		sort(cha+1,cha+i);
		int sum=0,cnt=0;
		for(int j=1;j<i;j++){
			sum+=cha[j];
			if(sum>m){
				break;
			}
			cnt++;
		}
		mcnt=max(mcnt,cnt);
	}
	cout<<mcnt+1;
	return 0;
} 
