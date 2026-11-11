#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long mm;
int a[205];
int maxn=-1;
int index;
long long ans,lans=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(m<=100000000){
		int tmp=0;
		for(int i=1;i<=n;i++){
			cin>>tmp;
			tmp+=100;
			a[tmp]++;
			maxn=max(maxn,a[tmp]);
		}
		for(int i=0;i<=200;i++){
			if(a[i]==maxn){
				index=1;
				ans=a[i];
				mm=m;
				while(mm>0){
					if(a[i-index]==0){
						index++;
						continue;
					}
					if(mm>=index*a[i-index]){
						mm-=index*a[i-index];
						ans+=a[i-index];
					}else{
						if(mm>=index){
							ans+=mm/index;
							mm=mm%index;
						}else{
							break;
						}
					}
					index++;
				}
				lans=max(lans,ans);	
			}
		}
		cout<<lans;
	}else{
		int a2[500005];
		for(int i=1;i<=n;i++){
			cin>>a2[i];
		}
		int dc=a2[2]-a2[1];
		if(m/dc>=n){
			cout<<n;
		}else{
			cout<<m/dc;
		}
	}
	return 0;
}

